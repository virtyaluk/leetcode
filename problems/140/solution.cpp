class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
    
    TrieNode() {}
};

class Solution {
private:
    TrieNode *root = new TrieNode();
    
    void addWord(string& s) {
        TrieNode *node = root;
        
        for (const char& ch: s) {
            if (not node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            
            node = node->children[ch];
        }
        
        node->isWord = true;
    }

    vector<string> dfs(string& s, int pos, unordered_map<int, vector<string>>& memo) {
        if (memo.count(pos)) {
            return memo[pos];
        }
        
        vector<string> ans;
        TrieNode *node = root;
        
        for (int i = pos; i < size(s); i++) {
            char ch = s[i];

            if (not node->children.count(ch)) {
                break;
            }
            
            node = node->children[ch];
            
            if (node->isWord) {
                string curSub = s.substr(pos, i - pos + 1);
                vector<string> next = dfs(s, i + 1, memo);
                
                if (i + 1 < size(s)) {
                    curSub += " ";
                }
                
                for (string& nextWord: next) {
                    ans.push_back(curSub + nextWord);
                }
            }
        }
        
        return memo[pos] = ans;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, vector<string>> memo = {{size(s), {""}}};
        
        for (string& word: wordDict) {
            addWord(word);
        }
        
        return dfs(s, 0, memo);
    }
};