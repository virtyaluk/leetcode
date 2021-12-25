class Solution {
public:
    vector<string> expand(string s) {
        vector<string> words = {""}, ans;
        bool isOption = false;
        
        for (const char& ch: s) {
            if (ch == ',') {
                continue;
            } else if (ch == '{') {
                isOption = true;
            } else if (ch == '}') {
                isOption = false;
                words.push_back("");
            } else {
                words.back() += ch;
                
                if (not isOption) {
                    words.push_back("");
                }
            }
        }
        
        for (string& word: words) {
            sort(begin(word), end(word));
        }
        
        dfs(words, ans, 0, "");
        
        return ans;
    }
    
    void dfs(vector<string>& words, vector<string>& ans, int idx, string curWord) {
        if (idx == size(words) - 1) {
            ans.push_back(curWord);
            return;
        }
        
        for (const char& ch: words[idx]) {
            curWord.push_back(ch);
            
            dfs(words, ans, idx + 1, curWord);
            
            curWord.pop_back();
        }
    }
};