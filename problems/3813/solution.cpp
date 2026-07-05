class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0,
            c = 0;
        
        for (const char& ch: s) {
            if (not isalpha(ch)) {
                continue;
            }

            if (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u') {
                v++;
            } else {
                c++;
            }
        }

        if (c <= 0) {
            return 0;
        }

        return floor(v / c);
    }
};