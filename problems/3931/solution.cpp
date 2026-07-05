class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for (int i = 1; i < size(s); i++) {
            if (abs(s[i] - s[i - 1]) > 2) {
                return false;
            }
        }

        return true;
    }
};