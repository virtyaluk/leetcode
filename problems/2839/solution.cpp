class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if (
            (s1.front() != s2.front() and s1.front() != s2[2])
            or
            (s1[1] != s2[1] and s1[1] != s2.back())
            or
            (s1[2] != s2[2] and s1[2] != s2.front())
            or
            (s1.back() != s2.back() and s1.back() != s2[1])
        ) {
            return false;
        }

        return true;
    }
};