class TrieNode {
public:
    TrieNode* next[2];
    
    TrieNode() {
        next[0] = nullptr;
        next[1] = nullptr;
    }
};

class Solution {
private:
    TrieNode* buildTrie(const vector<int>& nums) {
        TrieNode *trie = new TrieNode(), *node;
        
        for (const int& num: nums) {
            node = trie;
            
            for (int i = 31; i >= 0; i--) {
                int idx = (num >> i) & 1;
                
                if (node->next[idx] == nullptr) {
                    node->next[idx] = new TrieNode();
                }
                
                node = node->next[idx];
            }
        }
        
        return trie;
    }
    
    int helper(TrieNode *trie, int num) {
        int ans = 0;
        
        for (int i = 31; i >= 0; i--) {
            int idx = (num >> i) & 1 ? 0 : 1;
            
            if (trie->next[idx] != nullptr) {
                trie = trie->next[idx];
                ans <<= 1;
                ans |= 1;
            } else {
                trie = trie->next[idx ? 0 : 1];
                ans <<= 1;
                ans |= 0;
            }
        }
        
        return ans;
    }
    
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        TrieNode *trie = buildTrie(nums);
        
        for (const int& num: nums) {
            ans = max(ans, helper(trie, num));
        }
        
        return ans;
    }
};