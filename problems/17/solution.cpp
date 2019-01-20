class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (empty(digits)) {
            return {};
        }
        
        vector<string> ans;
        unordered_map<char, string> dialpad = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string candidate;
        function<void(int, string&)> backtrack;
        
        backtrack = [&](int idx, string& cand) {
            if (idx >= size(digits)) {
                ans.push_back(cand);
                return;
            }
            
            for (const char& ch: dialpad[digits[idx]]) {
                cand.push_back(ch);
                
                backtrack(idx + 1, cand);
                
                cand.pop_back();
            }
        };
        
        backtrack(0, candidate);
        
        return ans;
    }
};