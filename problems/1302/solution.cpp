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
    int deepestLeavesSum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int ans = 0;
        
        deque<TreeNode*> q;
        q.push_back(root);
        
        while (!q.empty()) {
            ans = 0;
            int curSize = q.size();
            
            while (curSize > 0) {
                TreeNode* node = q.front();
                ans += node->val;
                q.pop_front();
                
                if (node->left) {
                    q.push_back(node->left);
                }
                
                if (node->right) {
                    q.push_back(node->right);
                }
                
                curSize--;
            }
        }
        
        return ans;
    }
};