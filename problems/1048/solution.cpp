class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int ans = 1;
        unordered_map<string, int> dp;
        
        sort(begin(words), end(words), [](const string& lhs, const string& rhs) {
            return lhs.size() < rhs.size();
        });
        
        for (const string& word: words) {
            int curLen = 1;
            
            for (int i = 0; i < word.size(); i++) {
                string prevWord(word.substr(0, i) + word.substr(i + 1));
                curLen = max(curLen, 1 + dp[prevWord]);
            }
            
            dp[word] = curLen;
            ans = max(ans, curLen);
        }
        
        return ans;
    }
    
    int longestStrChain1(vector<string>& words) {
        int ans = 0;
        unordered_set<string> w(begin(words), end(words));
        unordered_map<string, int> len;
        
        for (const string& word: words) {
            dfs(w, len, word);
            
            ans = max(ans, len[word]);
        }
        
        return ans;
    }
    
    int dfs(const unordered_set<string>& words, unordered_map<string, int>& len, string word) {
        if (len.count(word)) {
            return len[word];
        }
        
        len[word] = 1;
        
        for (int i = 0; i < word.size(); i++) {
            string word2(word.substr(0, i) + word.substr(i + 1));
            
            if (words.count(word2)) {
                len[word] = max(len[word], dfs(words, len, word2) + 1);
            }
        }
        
        return len[word];
    }
};