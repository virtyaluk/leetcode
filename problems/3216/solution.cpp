class Solution {
public:
    string getSmallestString(string s) {
        for (int i = 1; i < size(s); i++) {
            if (s[i] < s[i - 1] and (s[i - 1] - '0') % 2 == (s[i] - '0') % 2) {
                swap(s[i - 1], s[i]);
                break;
            }
        }

        return s;
    }
};