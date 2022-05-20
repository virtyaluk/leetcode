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

const int MOD = 1e9 + 7;

class Solution {
public:
    int maxProduct(TreeNode* root) {
        int sum = getSum(root);
        long long int ans = 0;
        
        getMaxProduct(root, sum, ans);
        
        return ans % MOD;
    }
    
    int getSum(TreeNode* root) {
        if (not root) {
            return 0;
        }
        
        return root->val + getSum(root->left) + getSum(root->right);
    }
    
    int getMaxProduct(TreeNode* root, const int& sum, long long int& ans) {
        if (not root) {
            return 0;
        }
        
        int lSum = getMaxProduct(root->left, sum, ans),
            rSum = getMaxProduct(root->right, sum, ans);
        
        ans = max({
            ans,
            (long long int) (sum - lSum) * lSum,
            (long long int) (sum - rSum) * rSum
        });
        
        return root->val + lSum + rSum;
    }
};