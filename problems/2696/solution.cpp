class Solution {
public:
    int minLength(string s) {
        string ans = "";
        
        for (const char& ch: s) {
            ans.push_back(ch);
            
            if (size(ans) > 1) {
                int n = size(ans);
                
                if ((ans[n - 1] == 'B' and ans[n - 2] == 'A') or (ans[n - 1] == 'D' and ans[n - 2] == 'C')) {
                    ans.pop_back();
                    ans.pop_back();
                }
            }
        }
        
        return size(ans);
    }
};