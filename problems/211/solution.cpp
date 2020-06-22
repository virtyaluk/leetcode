class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
    
    TrieNode() {}
};

class WordDictionary {
private:
    TrieNode *root = new TrieNode();
    
    void insert(const string& s, TrieNode *node) {
        TrieNode *cur = node;
        
        for (const char& ch: s) {
            if (not cur->children.count(ch)) {
                cur->children[ch] = new TrieNode();
            }
            
            cur = cur->children[ch];
        }
        
        cur->isWord = true;
    }
    
    bool search(const string& s, TrieNode *node, int pos = 0) {
        TrieNode *cur = node;
        
        for (int i = pos; i < size(s); i++) {
            if (s[i] != '.') {
                if (not cur->children.count(s[i])) {
                    return false;
                }
                
                cur = cur->children[s[i]];
            } else {
                for (auto [ignore, child]: cur->children) {
                    if (search(s, child, i + 1)) {
                        return true;
                    }
                }
                
                return false;
            }
        }
        
        return cur and cur->isWord;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {}
    
    void addWord(string word) {
        insert(word, root);
    }
    
    bool search(string word) {
        return search(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */