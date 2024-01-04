class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> us;
        
        for (const char& ch: s) {
            if (us.count(ch)) {
                return ch;
            }
            
            us.insert(ch);
        }
        
        return '#';
    }
};