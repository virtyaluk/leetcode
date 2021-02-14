class Node {
public:
    unordered_map<char, Node*> children;
    int idx;
    
    Node() {
        
    }
};

class WordFilter {
private:
    Node *trie = new Node();
    
    void put(const string& str, const int idx) {
        for (int i = 0; i <= str.size(); i++) {
            string s = str.substr(str.size() - i) + "#" + str;
            
            Node *node = trie;
        
            for (const char& ch: s) {
                if (not node->children[ch]) {
                    node->children[ch] = new Node();
                }

                node = node->children[ch];
                node->idx = idx;
            }
        }
    }
    
    int find(const string& str) {
        Node *node = trie;
        
        for (const char& ch: str) {
            if (not node->children[ch]) {
                return -1;
            }
            
            node = node->children[ch];
        }
        
        return node->idx;
    }
    
public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            put(words[i], i);
        }
    }
    
    int f(string prefix, string suffix) {
        return find(suffix + "#" + prefix);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */