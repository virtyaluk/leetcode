class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> ans;
        string candidate;
        int l = 0, r = 0, n = size(s);
        function<void(int, int, int, int, int, string&)> backtrack;
        
        backtrack = [&](int i, int left, int right, int leftRem, int rightRem, string& cand) {
            if (i == n) {
                if (not leftRem and not rightRem) {
                    ans.insert(cand);
                }
                
                return;
            }
            
            char ch = s[i];
            
            if ((ch == '(' and leftRem > 0) or (ch == ')' and rightRem > 0)) {
                backtrack(i + 1, left, right, leftRem - (ch == '('), rightRem - (ch == ')'), cand);
            }
            
            cand.push_back(ch);
            
            if (ch != '(' and ch != ')') {
                backtrack(i + 1, left, right, leftRem, rightRem, cand);
            } else if (ch == '(') {
                backtrack(i + 1, left + 1, right, leftRem, rightRem, cand);
            } else if (right < left) {
                backtrack(i + 1, left, right + 1, leftRem, rightRem, cand);
            }
            
            cand.pop_back();
        };
        
        for (const char& ch: s) {
            if (ch == '(') {
                l++;
            } else if (ch == ')') {
                if (not l) {
                    r++;
                } else if (l > 0) {
                    l--;
                }
            }
        }
        
        backtrack(0, 0, 0, l, r, candidate);
        
        return {begin(ans), end(ans)};
    }
    
    vector<string> removeInvalidParentheses1(string s) {
        vector<string> ans;
        
        dfs(ans, s, 0, 0, new char[]{'(', ')'});
        
        return ans;
    }
    
    void dfs(vector<string>& ans, string s, int start, int end, char paren[2]) {
        int i = 0, count = 0, n = size(s);
        
        while (i < n and count >= 0) {
            if (s[i] == paren[0]) {
                count++;
            } else if (s[i] == paren[1]) {
                count--;
            }
            
            i++;
        }
        
        if (count >= 0) {
            string reversed(rbegin(s), rend(s));

            if (paren[0] == '(') {
                dfs(ans, reversed, 0, 0, new char[]{')', '('});
            } else {
                ans.push_back(reversed);
            }
        } else {
            i--;
            
            for (int j = end; j <= i; j++) {
                if (s[j] == paren[1] and (j == end or s[j - 1] != paren[1])) {
                    dfs(ans, s.substr(0, j) + s.substr(j + 1), i, j, paren);
                }
            }
        }
    }
    
    void dfs1(vector<string>& ans, string s, int start, int end, char paren[2]) {
        for (int i = start, count = 0; i < size(s); i++) {
            if (s[i] == paren[0]) {
                count++;
            } else if (s[i] == paren[1]) {
                count--;
            }
            
            if (count >= 0) {
                continue;
            }
            
            for (int j = end; j <= i; j++) {
                if (s[j] == paren[1] and (j == end or s[j - 1] != paren[1])) {
                    dfs(ans, s.substr(0, j) + s.substr(j + 1), i, j, paren);
                }
            }
            
            return;
        }
        
        string reversed(rbegin(s), rend(s));
        
        if (paren[0] == '(') {
            dfs(ans, reversed, 0, 0, new char[]{')', '('});
        } else {
            ans.push_back(reversed);
        }
    }
};