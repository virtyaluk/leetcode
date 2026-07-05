class Solution {
public:
    bool scoreBalance(string s) {
        int rightSum = 0;

        for (const char& ch: s) {
            rightSum += ch - 'a' + 1;
        }

        for (int i = 0, leftSum = 0; i < size(s); i++) {
            leftSum += s[i] - 'a' + 1;

            if (leftSum * 2 == rightSum) {
                return true;
            }
        }

        return false;
    }
};