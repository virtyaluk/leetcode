/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void buildParent(TreeNode *root, unordered_map<TreeNode*, TreeNode*>& parents) {
        if (not root) {
            return;
        }
        
        if (root->left) {
            parents[root->left] = root;
            buildParent(root->left, parents);
        }
        
        if (root->right) {
            parents[root->right] = root;
            buildParent(root->right, parents);
        }
    }
    
    void dfs(TreeNode *target, unordered_map<TreeNode*, TreeNode*>& parents, int k, vector<int>& ans, unordered_set<TreeNode*>& visited) {
        if (not target or visited.count(target)) {
            return;
        }
        
        visited.insert(target);
        
        if (not k) {
            ans.push_back(target->val);
            return;
        }
        
        dfs(parents[target], parents, k - 1, ans, visited);
        dfs(target->left, parents, k - 1, ans, visited);
        dfs(target->right, parents, k - 1, ans, visited);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (not root or not target) {
            return {};
        }
        
        vector<int> ans;
        unordered_map<TreeNode*, TreeNode*> parents;
        unordered_set<TreeNode*> visited;
        
        buildParent(root, parents);
        dfs(target, parents, k, ans, visited);
        
        return ans;
    }
};