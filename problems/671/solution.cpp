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
    int findSecondMinimumValue(TreeNode* root) {
        set<int> nums;
        
        dfs(root, nums);
        
        if (size(nums) < 2) {
            return -1;
        }
        
        return *next(nums.begin());
    }
    
    void dfs(TreeNode* root, set<int>& nums) {
        if (not root) {
            return;
        }
        
        nums.insert(root->val);
        
        dfs(root->left, nums);
        dfs(root->right, nums);
    }
};