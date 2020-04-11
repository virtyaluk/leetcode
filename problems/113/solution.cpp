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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        
        dfs(root, path, targetSum, ans);
        
        return ans;
    }
    
    void dfs(TreeNode *root, vector<int>& path, int sum, vector<vector<int>>& ans) {
        if (not root) {
            return;
        }
        
        path.push_back(root->val);
        sum -= path.back();
        
        if (not root->left and not root->right and sum == 0) {
            ans.push_back(path);
        } else {
            dfs(root->left, path, sum, ans);
            dfs(root->right, path, sum, ans);
        }
        
        path.pop_back();
    }
};