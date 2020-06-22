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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (not root) {
            return {};
        }
        
        int start = INT_MAX, end = INT_MIN;
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> um;
        queue<pair<TreeNode*, int>> q;
        
        q.push({root, 0});
        
        while (not q.empty()) {
            auto [node, pos] = q.front();
            q.pop();
            
            um[pos].push_back(node->val);
            start = min(start, pos);
            end = max(end, pos);
            
            if (node->left) {
                q.push({node->left, pos - 1});
            }
            
            if (node->right) {
                q.push({node->right, pos + 1});
            }
        }
        
        for (int i = start; i <= end; i++) {
            if (um.count(i)) {
                ans.push_back(um[i]);
            }
        }
        
        return ans;
    }
};