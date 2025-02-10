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
private:
    int height(TreeNode* node, unordered_map<TreeNode*, int>& um) {
        if (not node) {
            return -1;
        }
        
        if (um.count(node)) {
            return um[node];
        }
        
        int ans = 1 + max(height(node->left, um), height(node->right, um));
        um[node] = ans;
        
        return ans;
    }
    
    void dfs(TreeNode* node, unordered_map<int, int>& um1, unordered_map<TreeNode*, int>& um2, int depth, int maxVal) {
        if (not node) {
            return;
        }
        
        um1[node->val] = maxVal;
        
        dfs(node->left, um1, um2, depth + 1, max(maxVal, depth + 1 + height(node->right, um2)));
        dfs(node->right, um1, um2, depth + 1, max(maxVal, depth + 1 + height(node->left, um2)));
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int, int> um1;
        unordered_map<TreeNode*, int> um2;
        vector<int> ans(size(queries));
        
        dfs(root, um1, um2, 0, 0);
        
        for (int i = 0; i < size(queries); i++) {
            ans[i] = um1[queries[i]];
        }
        
        return ans;
    }
};