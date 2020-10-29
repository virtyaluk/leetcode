class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int count = 0;
    
    TrieNode() {};
};

class Solution {
private:
    void insert(TrieNode *root, string& word) {
        TrieNode *node = root;
        
        for (const char& ch: word) {
            if (not node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            
            node = node->children[ch];
            node->count++;
        }
    }
    
    string getAbbr(string& word, int index = 0) {
        if (size(word) - index <= 3) {
            return word;
        }
        
        string abbr = word.substr(0, index + 1) + to_string(size(word) - 2 - index);
        
        abbr.push_back(word.back());
        
        return abbr;
    }
    
    int find(TrieNode *root, string& word) {
        TrieNode *node = root;
        
        for (int i = 0; i < size(word); i++) {
            node = node->children[word[i]];
            
            if (node->count == 1) {
                return i;
            }
        }
        
        return 10;
    }
public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        vector<string> ans(size(words));
        unordered_map<string, vector<int>> groups;
        
        for (int i = 0; i < size(words); i++) {
            groups[getAbbr(words[i])].push_back(i);
        }
        
        for (auto [abbr, indices]: groups) {
            if (size(indices) == 1) {
                ans[indices.front()] = abbr;
            } else {
                TrieNode *trie = new TrieNode();
                
                for (const int& idx: indices) {
                    insert(trie, words[idx]);
                }
                
                for (const int& idx: indices) {
                    ans[idx] = getAbbr(words[idx], find(trie, words[idx]));
                }
            }
        }
        
        return ans;
    }
};