class Solution {
public:
    string reversePrefix(string s, int k) {
        reverse(begin(s), begin(s) + k);

        return s;
    }
};