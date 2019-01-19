class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    
    TrieNode() {}
};

class Solution {
private:
    TrieNode *root = new TrieNode();
    
    void insert(const string& str) {
        TrieNode *node = root;
        
        for (const char& ch: str) {
            if (not node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            
            node = node->children[ch];
        }
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int minLen = INT_MAX;
        TrieNode* node = root;
        
        for (const string& str: strs) {
            if (empty(str)) {
                return ans;
            }
            
            insert(str);
            minLen = min(minLen, (int) size(str));
        }
        
        while (node and size(node->children) == 1 and size(ans) < minLen) {
            auto it = begin(node->children);
            
            ans.push_back(it->first);
            node = it->second;
        }
        
        return ans;
    }
};