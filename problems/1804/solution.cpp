class TrieNode {
public:
    TrieNode() {}
    
    unordered_map<char, TrieNode*> children;
    int count = 0;
    int words = 0;
};

class Trie {
private:
    TrieNode *root = nullptr;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *cur = root;
        
        for (const char& ch: word) {
            if (not cur->children.count(ch)) {
                cur->children[ch] = new TrieNode();
            }
            
            cur = cur->children[ch];
            cur->count++;
        }
        
        cur->words++;
    }
    
    int countWordsEqualTo(string word) {
        TrieNode *cur = root;
        
        for (const char& ch: word) {
            if (not cur->children.count(ch)) {
                return 0;
            }
            
            cur = cur->children[ch];
        }
        
        return cur->words;
    }
    
    int countWordsStartingWith(string prefix) {
        TrieNode *cur = root;
        
        for (const char& ch: prefix) {
            if (not cur->children.count(ch)) {
                return 0;
            }
            
            cur = cur->children[ch];
        }
        
        return cur->count;
    }
    
    void erase(string word) {
        TrieNode *cur = root;
        
        for (const char& ch: word) {
            if (cur->children[ch]->count == 1) {
                cur->children.erase(ch);
                
                return;
            }
            
            cur = cur->children[ch];
            cur->count--;
        }
        
        cur->words--;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */