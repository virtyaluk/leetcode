class Solution {
public:
    string finalString(string s) {
        string ans;
        
        for (const char& ch: s) {
            if (ch == 'i') {
                reverse(begin(ans), end(ans));
            } else {
                ans.push_back(ch);
            }
        }
        
        return ans;
    }
};