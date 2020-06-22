class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
    
    TrieNode() {}
};

class Trie {
private:
    TrieNode *root = new TrieNode();

public:
    Trie() {
        
    }
    
    void insert(string word) {
        TrieNode *node = root;
        
        for (const char& ch: word) {
            if (not node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            
            node = node->children[ch];
        }
        
        node->isWord = true;
    }
    
    bool search(string word) {
        TrieNode *node = root;
        
        for (const char& ch: word) {
            if (not node->children.count(ch)) {
                return false;
            }
            
            node = node->children[ch];
        }
        
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = root;
        
        for (const char& ch: prefix) {
            if (not node->children.count(ch)) {
                return false;
            }
            
            node = node->children[ch];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */