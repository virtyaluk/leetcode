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
    int getHeight(TreeNode* root) {
        if (not root) {
            return 0;
        }
        
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        if (not root) {
            return {};
        }
        
        int height = getHeight(root) - 1,
            m = height + 1,
            n = pow(2, m) - 1;
        vector<vector<string>> ans(m, vector<string>(n));
        queue<tuple<TreeNode*, int, int>> q;
        
        q.push({root, 0, (n - 1) / 2});
        
        while (not empty(q)) {
            auto [node, x, y] = q.front();
            q.pop();
            
            ans[x][y] = to_string(node->val);
            
            if (node->left) {
                q.push({node->left, x + 1, y - pow(2, height - x - 1)});
            }
            
            if (node->right) {
                q.push({node->right, x + 1, y + pow(2, height - x - 1)});
            }
        }
        
        return ans;
    }
};