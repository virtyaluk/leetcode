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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        int minCol = INT_MAX, maxCol = INT_MIN;
        unordered_map<int, vector<pair<int, int>>> m;
        queue<tuple<TreeNode*, int, int>> q;
        auto sortFn = [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
            if (lhs.first == rhs.first) {
                return lhs.second < rhs.second;
            }
            
            return lhs.first < rhs.first;
        };
        
        q.push({root, 0, 0});
        
        while (!q.empty()) {
            auto [node, x, y] = q.front();
            q.pop();
            
            if (!node) {
                continue;
            }
            
            minCol = min(minCol, x);
            maxCol = max(maxCol, x);
            
            m[x].push_back({y, node->val});
            q.push({node->left, x - 1, y + 1});
            q.push({node->right, x + 1, y + 1});
        }
        
        for (int i = minCol; i <= maxCol; i++) {
            sort(m[i].begin(), m[i].end(), sortFn);
            
            ans.push_back({});
            
            for (const pair<int, int>& p: m[i]) {
                ans.back().push_back(p.second);
            }
        }
        
        return ans;
    }
};