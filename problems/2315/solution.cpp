class Solution {
public:
    int countAsterisks(string s) {
        int ans = 0,
            flag = 0;
        
        for (const char& ch: s) {
            flag ^= ch == '|';
            ans += not flag and ch == '*';
        }
        
        return ans;
    }
};