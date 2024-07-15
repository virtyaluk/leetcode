class Solution {
public:
    bool isPrefixString(string s, vector<string>& words, int i = 0) {
        for (int j = 0; j < size(words) and i < size(s); j++) {
            for (const char& ch : words[j]) {
                if (i == size(s) or s[i++] != ch) {
                    return false;
                }
            }
        }
        
        return i == size(s);
    }
};