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
    int ans = 0;
    int maxAncestorDiff(TreeNode* root) {
        traverse(root, INT_MAX, INT_MIN);
        
        return ans;
    }
    
    void traverse(TreeNode* node, int curMin, int curMax) {
        if (!node) {
            return;
        }
        
        curMin = min(curMin, node->val);
        curMax = max(curMax, node->val);
        ans = max(ans, curMax - curMin);
        
        traverse(node->left, curMin, curMax);
        traverse(node->right, curMin, curMax);
    }
};