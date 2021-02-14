class Solution {
public:
    string toLowerCase(string s) {
        string ans;
        
        for (const char& ch: s) {
            if (ch >= 64 and ch <= 90) {
                ans += (ch + 32);
            } else {
                ans += ch;
            }
        }
        
        return ans;
    }
};