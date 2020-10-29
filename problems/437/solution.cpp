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
    int pathSum(TreeNode* root, int targetSum) {
        long long int ans = 0;
        unordered_map<long long int, int> um;
        
        dfs(root, targetSum, um, 0, ans);
        
        return ans;
    }
    
    void dfs(TreeNode* root, int k, unordered_map<long long int, int>& um, long long int curSum, long long int& ans) {
        if (not root) {
            return;
        }
        
        curSum += root->val;
        ans += (curSum == k);
        ans += um[curSum - k];
        um[curSum]++;
        
        dfs(root->left, k, um, curSum, ans);
        dfs(root->right, k, um, curSum, ans);
        
        um[curSum]--;
    }
};