class Solution {
public:
    vector<string> printVertically(string s) {
        stringstream ss(s);
        string token;
        vector<string> words;
        int n = 0;
        
        while(getline(ss, token, ' ')) {
            words.push_back(token);
            n = max(n, (int) token.size());
        }
        
        vector<string> ans(n);
        
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < n; j++) {
                if (j < words[i].size()) {
                    ans[j] += words[i][j];
                } else {
                    ans[j] += ' ';
                }
            }
        }
        
        for (int i = 0; i < ans.size(); i++) {
            while (isspace(ans[i].back())) {
                ans[i].pop_back();
            }
        }
        
        return ans;
    }
};