class Solution {
public:
    string longestPalindrome(string s) {
        int len = 0, start = 0;
        
        for (int i = 0; i < size(s); i++) {
            int first = maxPal(s, i, i),
                second = maxPal(s, i, i + 1),
                curLen = max(first, second);
            
            if (curLen > len) {
                len = curLen;
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, len);
    }
    
    int maxPal(const string& str, int lo, int hi) {
        while (lo >= 0 and hi < size(str) and str[lo] == str[hi]) {
            lo--;
            hi++;
        }
        
        return hi - lo - 1;
    }
};