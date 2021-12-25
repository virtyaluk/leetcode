class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        if (k > size(s)) {
            return 0;
        }
        
        int ans = 0;
        unordered_map<char, int> freq;
        
        for (int i = 0; i < size(s); i++) {
            if (i >= k) {
                freq[s[i - k]]--;
                
                if (not freq[s[i - k]]) {
                    freq.erase(s[i - k]);
                }
            }
            
            freq[s[i]]++;
            ans += size(freq) == k;
        }
        
        return ans;
    }
};