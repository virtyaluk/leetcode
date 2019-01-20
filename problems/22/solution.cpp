class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string token;
        function<void(string&, int, int)> backtrack;
        
        backtrack = [&](string& str, int open, int close) {
            if (size(str) == 2 * n) {
                ans.push_back(str);
                return;
            }
            
            if (open < n) {
                str.push_back('(');
                backtrack(str, open + 1, close);
                str.pop_back();
            }
            
            if (close < open) {
                str.push_back(')');
                backtrack(str, open, close + 1);
                str.pop_back();
            }
        };
        
        backtrack(token, 0, 0);
        
        return ans;
    }
};