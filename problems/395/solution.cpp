class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0, maxUniq = 0;
        unordered_set<char> chs;
        
        for (char ch: s) {
            chs.insert(ch);
        }
        
        maxUniq = chs.size();
        
        for (int curUniq = 1; curUniq <= maxUniq; curUniq++) {
            int lo = 0, hi = 0, atLeastK = 0, uniq = 0;
            unordered_map<char, int> counter;
            
            while (hi < s.size()) {
                if (uniq <= curUniq) {
                    if (counter.find(s[hi]) == counter.end() || counter[s[hi]] == 0) {
                        counter[s[hi]]++;
                        uniq++;
                    } else {
                        counter[s[hi]]++;
                    }
                    
                    if (counter[s[hi]] == k) {
                        atLeastK++;
                    }
                    
                    hi++;
                } else {
                    if (counter[s[lo]] == k) {
                        atLeastK--;
                    }
                    
                    counter[s[lo]]--;
                    
                    if (counter[s[lo]] == 0) {
                        uniq--;
                    }
                    
                    lo++;
                }
                
                if (uniq == curUniq && atLeastK == uniq) {
                    ans = max(ans, hi - lo);
                }
            }
        }
        
        return ans;
    }
};