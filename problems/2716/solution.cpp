class Solution {
public:
    int minimizedStringLength(string s) {
        return size(unordered_set<char>(begin(s), end(s)));
    }
};