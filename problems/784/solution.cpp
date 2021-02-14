class Solution {
public:
    vector<string> letterCasePermutation1(string S) {
        vector<string> ans;
        function<void(string, int)> backtrack;
        
        backtrack = [&](string s, const int pos) {
            if (pos == S.size()) {
                ans.push_back(s);
                return;
            }
            
            if (isalpha(S[pos])) {
                s.push_back(tolower(S[pos]));
                backtrack(s, pos + 1);
                s.pop_back();
                s.push_back(toupper(S[pos]));
                backtrack(s, pos + 1);
            } else {
                backtrack(s + S[pos], pos + 1);
            }
        };
        
        backtrack("", 0);
        
        return ans;
    }
    
    vector<string> letterCasePermutation(string S) {
        vector<string> ans = {""};
        
        for (const char& ch: S) {
            if (isalpha(ch)) {
                vector<string> tmp;
                
                for (string s: ans) {
                    tmp.push_back(s + (char) tolower(ch));
                    tmp.push_back(s + (char) toupper(ch));
                }
                
                ans = tmp;
            } else {
                for (string& s: ans) {
                    s.push_back(ch);
                }
            }
        }
        
        return ans;
    }
};