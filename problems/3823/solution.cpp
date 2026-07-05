class Solution {
public:
    string reverseByType(string s) {
        for (int lo = 0, hi = size(s) - 1; lo < hi;) {
            if (not isalpha(s[lo])) {
                lo++;
            } else if (not isalpha(s[hi])) {
                hi--;
            } else {
                swap(s[lo], s[hi]);
                lo++;
                hi--;
            }
        }

        for (int lo = 0, hi = size(s) - 1; lo < hi;) {
            if (isalpha(s[lo])) {
                lo++;
            } else if (isalpha(s[hi])) {
                hi--;
            } else {
                swap(s[lo], s[hi]);
                lo++;
                hi--;
            }
        }

        return s;
    }
};