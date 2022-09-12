/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checkEquivalence(Node* root1, Node* root2) {
        if (!root1 || !root2) {
            return false;
        }
        
        unordered_map<char, int> m;
        
        helper(m, root1);
        helper(m, root2, true);
        
        for (auto [_, count]: m) {
            if (count != 0) {
                return false;
            }
        }
        
        return true;
    }
    
    void helper(unordered_map<char, int>& m, Node* node, bool sub = false) {
        if (!node) {
            return;
        }
        
        if (node->val == '+') {
            helper(m, node->left, sub);
            helper(m, node->right, sub);
        } else {
            m[node->val] += sub ? -1 : 1;
        }
    }
};