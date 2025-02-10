class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        
        for (const char& ch: s) {
            if (size(ans) >= 2 and ch == ans.back() and ch == ans[size(ans) - 2]) {
                continue;
            }
            
            ans.push_back(ch);
        }
        
        return ans;
    }
};