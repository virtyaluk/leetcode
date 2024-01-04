class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if (size(words) != size(s)) {
            return false;
        }
        
        for (int i = 0; i < size(s); i++) {
            if (i >= size(words) or words[i][0] != s[i]) {
                return false;
            }
        }
        
        return true;
    }
};