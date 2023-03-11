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
    void dfs(TreeNode* node, int lvl, unordered_map<int, vector<TreeNode*>>& um) {
        if (not node) {
            return;
        }
        
        if (lvl % 2) {
            um[lvl].push_back(node);
        }
        
        dfs(node->left, lvl + 1, um);
        dfs(node->right, lvl + 1, um);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        unordered_map<int, vector<TreeNode*>> um;
        
        dfs(root, 0, um);
        
        for (auto [lvl, nodes]: um) {
            int lo = 0, hi = size(nodes) - 1;
            
            while (lo < hi) {
                swap(nodes[lo++]->val, nodes[hi--]->val);
            }
        }
        
        return root;
    }
};