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

    int longestConsecutive(TreeNode* root) {
        helper(root);
        
        return ans;
    }
    
    pair<int, int> helper(TreeNode *root) {
        if (!root) {
            return {0, 0};
        }
        
        int inc = 1, dec = 1;
        
        if (root->left) {
            auto [incLeft, decLeft] = helper(root->left);
            
            if (root->left->val + 1 == root->val) {
                inc += incLeft;
            } else if (root->left->val - 1 == root->val) {
                dec += decLeft;
            }
        }
        
        if (root->right) {
            auto [incRight, decRight] = helper(root->right);
            
            if (root->right->val + 1 == root->val) {
                inc = max(inc, incRight + 1);
            } else if (root->right->val - 1 == root->val) {
                dec = max(dec, decRight + 1);
            }
        }
        
        ans = max(ans, inc + dec - 1);
        
        return {inc, dec};
    }
};