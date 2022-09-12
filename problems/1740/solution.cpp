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
    TreeNode* parent = nullptr;
public:
    int findDistance(TreeNode* root, int p, int q) {
        if (p == q) {
            return 0;
        }
        
        int ans = 0;
        
        dfs1(root, {p, q});
        dfs2(parent, 0, p, q, ans);
        
        return ans;
    }
    
    int dfs1(TreeNode* root, unordered_set<int> target) {
        if (not root) {
            return 0;
        }
        
        int cur = dfs1(root->left, target) + dfs1(root->right, target) + target.count(root->val);
        
        if (parent == nullptr and cur >= size(target)) {
            parent = root;
        }
        
        return cur;
    }
    
    void dfs2(TreeNode* root, int dist, int p, int q, int& ans) {
        if (not root) {
            return;
        }
        
        if (root->val == p) {
            ans += dist;
        }
        
        if (root->val == q) {
            ans += dist;
        }
        
        dfs2(root->left, dist + 1, p, q, ans);
        dfs2(root->right, dist + 1, p, q, ans);
    }
};