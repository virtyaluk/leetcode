class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
    
    TrieNode() {}
};

class Solution {
private:
    TrieNode *root = new TrieNode();
    
    void addWord(string word) {
        TrieNode *node = root;
        
        for (const char& ch: word) {
            if (not node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            
            node = node->children[ch];
        }
        
        node->isWord = true;
    }
    
    bool search(string word, int pos, unordered_map<int, bool>& memo) {
        if (pos >= size(word)) {
            return true;
        } else if (memo.count(pos)) {
            return memo[pos];
        }
        
        TrieNode *node = root;
        
        for (int i = pos; i < size(word); i++) {
            char ch = word[i];

            if (not node->children.count(ch)) {
                return memo[pos] = false;
            }
            
            node = node->children[ch];
            
            if (node->isWord and search(word, i + 1, memo)) {
                return memo[pos] = true;
            }
        }
        
        return node and node->isWord;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, bool> memo;
        
        for (const string& word: wordDict) {
            addWord(word);
        }
        
        return search(s, 0, memo);
    }
    
    bool wordBreak1(string s, vector<string>& wordDict) {
        unordered_set<string> words(begin(wordDict), end(wordDict));
        unordered_map<string, bool> memo;
        
        return dfs(memo, words, s);
    }
    
    bool dfs(unordered_map<string, bool>& memo, unordered_set<string>& words, string word) {
        if (memo.count(word)) {
            return memo[word];
        }
        
        if (words.count(word)) {
            return memo[word] = true;
        }
        
        for (int i = 1; i < size(word); i++) {
            if (words.count(word.substr(0, i))) {
                string suf = word.substr(i);
                
                if (words.count(suf) or dfs(memo, words, suf)) {
                    return memo[word] = true;
                }
            }
        }
        
        return memo[word] = false;
    }
};