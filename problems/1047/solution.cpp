class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        
        for (const char& ch: s) {
            if (not empty(ans) and ans.back() == ch) {
                ans.pop_back();
            } else {
                ans.push_back(ch);
            }
        }
        
        return ans;
    }
};