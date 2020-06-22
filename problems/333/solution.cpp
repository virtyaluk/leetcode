const int m = INT_MIN, M = INT_MAX;

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
    int largestBSTSubtree(TreeNode* root) {
        int ans = 0;
        
        helper(root, ans);
        
        return ans;
    }
    
    // int_max, int_min, nodes_count
    tuple<int, int, int> helper(TreeNode* node, int& ans) {    
        if (!node) {
            return {M, m, 0};
        }
        
        auto [leftMin, leftMax, leftNodesCount] = helper(node->left, ans);
        auto [rightMin, rightMax, rightNodesCount] = helper(node->right, ans);
        
        if (leftNodesCount == -1 || rightNodesCount == -1) {
            return {m, M, -1};
        }
        
        if (node->val > leftMax && node->val < rightMin) {
            int nodesCount = leftNodesCount + rightNodesCount + 1;
            ans = max(ans, nodesCount);
            
            return {
                min(node->val, leftMin),
                max(node->val, rightMax),
                nodesCount
            };
        }
        
        return {m, M, -1};
    }
};