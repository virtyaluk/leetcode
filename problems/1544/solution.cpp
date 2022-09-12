class Solution {
public:
    string makeGood(string s) {
        string ans;
        
        for (const char& ch: s) {
            if (not empty(ans) and ch != ans.back() and tolower(ch) == tolower(ans.back())) {
                ans.pop_back();
            } else {
                ans.push_back(ch);
            }
        }
        
        return ans;
    }
};