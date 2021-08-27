/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> sq1, sq2;
        
        traverse(root1, &sq1);
        traverse(root2, &sq2);
        
        if (sq1.size() != sq2.size()) {
            return false;
        }
        
        for (int i = 0; i < sq1.size(); i++) {
            if (sq1[i] != sq2[i]) {
                return false;
            }
        }
        
        return true;
    }
    
    void traverse(TreeNode* node, vector<int>* sq) {
        if (!node) {
            return;
        }
        
        if (!node->left && !node->right) {
            sq->push_back(node->val);
        }

        traverse(node->left, sq);
        traverse(node->right, sq);
    }
};