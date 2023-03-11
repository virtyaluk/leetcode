class Solution {
public:
    string removeStars(string s) {
        string ans;
        
        for (const char& ch: s) {
            if (ch != '*') {
                ans.push_back(ch);
            } else {
                ans.pop_back();
            }
        }
        
        return ans;
    }
};