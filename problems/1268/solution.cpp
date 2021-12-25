class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
    
    TrieNode() {}
};

class Solution {
private:
    TrieNode *root = new TrieNode();
    
    void insert(string& word) {
        TrieNode *node = root;
        
        for (const char& ch: word) {
            if (not node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            
            node = node->children[ch];
        }
        
        node->isWord = true;
    }
    
    void prefixDfs(TrieNode *node, string& prefix, vector<string>& ans) {
        if (size(ans) == 3) {
            return;
        }
        
        if (node->isWord) {
            ans.push_back(prefix);
        }
        
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (node->children.count(ch)) {
                prefix.push_back(ch);
                prefixDfs(node->children[ch], prefix, ans);
                prefix.pop_back();
            }
        }
    }
    
    vector<string> findPrefixedWords(string& prefix) {
        vector<string> ans;
        TrieNode *node = root;
        
        for (const char& ch: prefix) {
            if (not node->children.count(ch)) {
                return ans;
            }
            
            node = node->children[ch];
        }
        
        prefixDfs(node, prefix, ans);
        
        return ans;
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        string prefix;
        
        for (string& word: products) {
            insert(word);
        }
        
        for (const char& ch: searchWord) {
            prefix.push_back(ch);
            ans.push_back(findPrefixedWords(prefix));
        }
        
        return ans;
    }
    
    vector<vector<string>> suggestedProducts1(vector<string>& products, string searchWord) {
        vector<vector<string>> ans(searchWord.size());
        
        sort(begin(products), end(products));
        
        for (int i = 0; i < searchWord.size(); i++) {
            string prefix = searchWord.substr(0, i + 1);
            
            for (const string& word: products) {
                if (word.find(prefix) == 0) {
                    ans[i].push_back(word);
                }
                
                if (ans[i].size() == 3) {
                    break;
                }
            }
        }
        
        return ans;
    }
};