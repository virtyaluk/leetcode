struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool endOfWord = false;
};

class Trie {
private:
    TrieNode *root = new TrieNode();

public:
    Trie() {}
    
    void insert(const string& s) {
        TrieNode *cur = root;
        
        for (auto it = s.rbegin(); it != s.rend(); it++) {
            const char ch = *it;
            
            if (not cur->children.count(ch)) {
                cur->children[ch] = new TrieNode();
            }
            
            cur = cur->children[ch];
        }
        
        cur->endOfWord = true;
    }
    
    int countPathsInTrie() {
        int ans = 0;
        queue<pair<TrieNode*, int>> q;
        
        q.push({root, 0});
        
        while (not q.empty()) {
            auto [node, len] = q.front();
            q.pop();
            
            len++;
            
            if (node->children.empty()) {
                ans += len;
                continue;
            }
            
            for (auto [ignore, next]: node->children) {
                q.push({next, len});
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie *trie = new Trie();
        
        for (const string& word: words) {
            trie->insert(word);
        }
        
        return trie->countPathsInTrie();
    }
};