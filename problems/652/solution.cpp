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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string, vector<TreeNode*>> um;
        
        helper(root, um);
        
        for (auto [ignore, nodes]: um) {
            if (size(nodes) > 1) {
                ans.push_back(nodes[0]);
            }
        }
        
        return ans;
    }
    
    string helper(TreeNode *root, unordered_map<string, vector<TreeNode*>>& um) {
        if (not root) {
            return "";
        }
        
        string serialize = "(" + helper(root->left, um) + to_string(root->val) + helper(root->right, um) + ")";
        
        // cout << serialize << endl;
        um[serialize].push_back(root);
        
        return serialize;
    }
};