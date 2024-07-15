class Solution {
public:
    int minFlips(string target) {
        int ans = 0;
        char start = '0';
        
        for (const char& ch: target) {
            if (start != ch) {
                ans++;
                start = ch;
            }
        }
        
        return ans;
    }
};