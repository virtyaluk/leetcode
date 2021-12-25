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
    double maximumAverageSubtree(TreeNode* root) {
        double ans = 0.0;
        
        helper(root, ans);
        
        return ans;
    }
    
    pair<double, int> helper(TreeNode *root, double& ans) {
        if (not root) {
            return {0.0, 0};
        }
        
        auto [leftSum, leftCount] = helper(root->left, ans);
        auto [rightSum, rightCount] = helper(root->right, ans);
        double sum = leftSum + rightSum + root->val;
        int nodesNum = leftCount + rightCount + 1;
        
        ans = max(ans, sum / nodesNum);
        
        return {sum, nodesNum};
    }
};