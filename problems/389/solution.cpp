class Solution {
public:
    char findTheDifference(string s, string t) {
        int ch = 0;
        
        for (char c: s + t) {
            ch ^= (int) c;
        }
        
        return (char) ch;
    }
};