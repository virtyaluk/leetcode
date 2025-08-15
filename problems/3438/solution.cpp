class Solution {
public:
    string findValidPair(string s) {
        unordered_map<char, int> um;

        for (const char& ch: s) {
            um[ch]++;
        }

        for (int i = 1; i < size(s); i++) {
            if (s[i - 1] != s[i] and um[s[i - 1]] == (s[i - 1] - '0') and um[s[i]] == (s[i] - '0')) {
                return string(1, s[i - 1]) + string(1, s[i]);
            }
        }

        return "";
    }
};