class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> um;
        string ans, token;
        bool startToken = false;
        
        for (const vector<string>& know: knowledge) {
            um[know.front()] = know.back();
        }
        
        for (const char& ch: s) {
            if (ch == '(') {
                startToken = true;
                token.clear();
            } else if (ch == ')') {
                startToken = false;
                
                if (um.count(token)) {
                    ans += um[token];
                } else {
                    ans.push_back('?');
                }
            } else if (startToken) {
                token.push_back(ch);
            } else {
                ans.push_back(ch);
            }
        }
        
        return ans;
    }
};