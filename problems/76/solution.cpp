class Solution {
public:
    string minWindow(string s, string t) {
        if (empty(s) or empty(t)) {
            return "";
        }
        
        int minLen = INT_MAX, lo, hi, gotUniqueChars = 0, hasUniqueChars;
        unordered_map<char, int> sCounter, tCounter;
        
        for (const char& ch: t) {
            tCounter[ch]++;
        }
        
        hasUniqueChars = size(tCounter);
        
        for (int left = 0, right = 0; right < size(s); right++) {
            char ch = s[right];
            sCounter[ch]++;
            
            if (tCounter.count(ch) and sCounter[ch] == tCounter[ch]) {
                gotUniqueChars++;
            }
            
            while (left <= right and gotUniqueChars == hasUniqueChars) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    lo = left;
                    hi = right;
                }
                
                ch = s[left++];
                sCounter[ch]--;
                
                if (sCounter[ch] < tCounter[ch]) {
                    gotUniqueChars--;
                }
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(lo, hi - lo + 1);
    }
};