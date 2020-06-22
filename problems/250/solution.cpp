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
private:
    int ans;
public:
    int countUnivalSubtrees(TreeNode* root) {
        isValidPart(root, 0);
        
        return ans;
    }
    
    bool isValidPart(TreeNode* node, int val) {
        if (!node) {
            return true;
        }
        
        if (!isValidPart(node->left, node->val) | !isValidPart(node->right, node->val)) {
            return false;
        }
        
        ans++;
        
        return node->val == val;
    }
};