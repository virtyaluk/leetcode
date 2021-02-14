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
    vector<double> averageOfLevels(TreeNode* root) {
        if (not root) {
            return {};
        }
        
        vector<double> ans;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while (not q.empty()) {
            int levelSize = q.size();
            double curLevelMean = 0.0;
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode *node = q.front();
                q.pop();
                
                curLevelMean += node->val;
                
                if (node->left) {
                    q.push(node->left);
                }
                
                if (node->right) {
                    q.push(node->right);
                }
            }
            
            ans.push_back(curLevelMean / levelSize);
        }
        
        return ans;
    }
};