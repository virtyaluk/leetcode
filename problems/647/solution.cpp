class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        
        for (int i = 0; i < s.size(); i++) {
            ans += countPalindromicSubstrings(s, i, i);
            ans += countPalindromicSubstrings(s, i, i + 1);
        }
        
        return ans;
    }
    
    int countPalindromicSubstrings(const string& s, int lo, int hi) {
        int ans = 0;
        
        while (lo >= 0 and hi < s.size()) {
            if (s[lo] != s[hi]) {
                break;
            }
            
            lo--;
            hi++;
            ans++;
        }
        
        return ans;
    }
};