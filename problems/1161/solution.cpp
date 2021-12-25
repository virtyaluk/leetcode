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
    int maxLevelSum(TreeNode* root) {
        if (not root) {
            return 0;
        }
        
        int ans, curMax = INT_MIN, level = 0;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while (not q.empty()) {
            int curSum = 0;
            level++;
            
            for (int qlen = q.size() - 1; qlen >= 0; qlen--) {
                TreeNode *node = q.front();
                q.pop();
                
                curSum += node->val;
                
                if (node->left) {
                    q.push(node->left);
                }
                
                if (node->right) {
                    q.push(node->right);
                }
            }
            
            if (curSum > curMax) {
                curMax = curSum;
                ans = level;
            }
        }
        
        return ans;
    }
};