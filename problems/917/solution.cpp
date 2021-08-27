class Solution {
public:
    string reverseOnlyLetters(string s) {
        int lo = 0, hi = size(s) - 1;
        
        while (lo <= hi) {
            if (not isalpha(s[lo])) {
                lo++;
            } else if (not isalpha(s[hi])) {
                hi--;
            } else {
                swap(s[lo++], s[hi--]);
            }
        }
        
        return s;
    }
};