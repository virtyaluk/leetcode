class Solution {
public:
    bool hasSameDigits(string s) {
        while (size(s) > 2) {
            string next;

            for (int i = 0; i < size(s) - 1; i++) {
                next.push_back('0' + ((s[i] - '0') + (s[i + 1] - '0')) % 10);
            }

            s = next;
        }

        return s.front() == s.back();
    }
};