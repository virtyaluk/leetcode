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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        TreeNode *ans = nullptr;
        unordered_set<TreeNode*> us(begin(nodes), end(nodes));
        
        helper(root, ans, us);
        
        return ans;
    }
    
    int helper(TreeNode* root, TreeNode *&ans, unordered_set<TreeNode*>& nodes) {
        if (not root) {
            return 0;
        }
        
        int math = helper(root->left, ans, nodes)
            + helper(root->right, ans, nodes)
            + nodes.count(root);
        
        if (math >= size(nodes) and not ans) {
            ans = root;
        }
        
        return math;
    }
};