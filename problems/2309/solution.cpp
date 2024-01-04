class Solution {
public:
    string greatestLetter(string s) {
        char ans = '#';
        unordered_map<char, pair<bool, bool>> um;
        
        for (const char& ch: s) {
            char uch = toupper(ch);
            um[uch].first |= islower(ch);
            um[uch].second |= isupper(ch);
            
            if (um[uch].first and um[uch].second) {
                ans = max(ans, uch);
            }
        }
        
        if (ans == '#') {
            return "";
        }
        
        return {ans};
    }
};