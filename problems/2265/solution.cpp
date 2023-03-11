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
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        
        dfs(root, ans);
        
        return ans;
    }
    
    pair<int, int> dfs(TreeNode* root, int& ans) {
        if (not root) {
            return {0, 0};
        }
        
        int sum = root->val, cnt = 1;
        auto[lsum, lcount] = dfs(root->left, ans);
        auto [rsum, rcount] = dfs(root->right, ans);
        
        cnt += lcount + rcount;
        sum += lsum + rsum;
        
        if (sum / cnt == root->val) {
            ans++;
        }
        
        return {sum, cnt};
    }
};