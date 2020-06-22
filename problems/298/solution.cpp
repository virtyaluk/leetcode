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
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        queue<tuple<TreeNode*, int, int>> q;
        
        q.push({root, 1, INT_MIN});
        
        while (!q.empty()) {
            auto [node, curStreak, prevVal] = q.front();
            q.pop();
            
            if (!node) {
                continue;
            }
            
            curStreak = prevVal + 1 == node->val ? curStreak + 1 : 1;
            ans = max(ans, curStreak);
            
            q.push({node->left, curStreak, node->val});
            q.push({node->right, curStreak, node->val});
        }
        
        return ans;
    }
};