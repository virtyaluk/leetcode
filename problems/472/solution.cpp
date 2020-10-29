class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        unordered_map<string, bool> memo;
        unordered_set<string> wordsSet(begin(words), end(words));
        
        for (const string& word: wordsSet) {
            if (dfs(memo, wordsSet, word)) {
                ans.push_back(word);
            }
        }
        
        return ans;
    }
    
    bool dfs(unordered_map<string, bool>& memo, unordered_set<string>& wordsSet, string word) {
        if (memo.count(word)) {
            return memo[word];
        }
        
        for (int i = 1; i < size(word); i++) {
            if (wordsSet.count(word.substr(0, i))) {
                string suf = word.substr(i);
                
                if (wordsSet.count(suf) or dfs(memo, wordsSet, suf)) {
                    return memo[word] = true;
                }
            }
        }
        
        return memo[word] = false;
    }
};