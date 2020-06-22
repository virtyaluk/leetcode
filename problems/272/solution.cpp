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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> ans;
        priority_queue<pair<double, int>> pq;
        
        dfs(root, target, k, pq);
        
        while (not empty(pq)) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
    
    void dfs(TreeNode* root, const double& target, const int& k, priority_queue<pair<double, int>>& pq) {
        if (not root) {
            return;
        }
        
        pq.push({fabs(target - double(root->val)), root->val});
        
        if (size(pq) > k) {
            pq.pop();
        }
        
        dfs(root->left, target, k, pq);
        dfs(root->right, target, k, pq);
    }
};