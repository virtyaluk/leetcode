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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> toDel(begin(to_delete), end(to_delete));
        
        helper(root, ans, toDel, true);
        
        return ans;
    }
    
    TreeNode* helper(TreeNode* root, vector<TreeNode*>& ans, unordered_set<int>& toDel, bool parentRemoved) {
        if (not root) {
            return nullptr;
        }
        
        bool removed = toDel.count(root->val);
        
        if (parentRemoved and not removed) {
            ans.push_back(root);
        }
        
        root->left = helper(root->left, ans, toDel, removed);
        root->right = helper(root->right, ans, toDel, removed);
        
        return removed ? nullptr : root;
    }
};