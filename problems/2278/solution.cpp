class Solution {
public:
    int percentageLetter(string s, char letter) {
        return 100.0 / (double) size(s) * count(begin(s), end(s), letter);
    }
};