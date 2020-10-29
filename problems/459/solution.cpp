class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).substr(1, 2 * size(s) - 2).find(s) != string::npos;
    }
};