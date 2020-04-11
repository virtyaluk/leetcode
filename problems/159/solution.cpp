class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.size() < 3) {
            return s.size();
        }
        
        int ans = 2, left = 0, right = 0;
        unordered_map<char, int> m;
        
        while (right < s.size()) {
            m[s[right]] = right;
            right++;
            
            if (m.size() == 3) {
                int delIdx = INT_MAX;
                
                for (auto [_, idx]: m) {
                    delIdx = min(delIdx, idx);
                }
                
                m.erase(s[delIdx]);
                left = delIdx + 1;
            }
            
            ans = max(ans, right - left);
        }
        
        return ans;
    }
};