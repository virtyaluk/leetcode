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
    void dfs(TreeNode* root, unordered_map<int, long long>& um, int lvl) {
        if (not root) {
            return;
        }
        
        um[lvl] += root->val;
        
        dfs(root->left, um, lvl + 1);
        dfs(root->right, um, lvl + 1);
    }
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        unordered_map<int, long long> um;
        priority_queue<long long, vector<long long>, greater<>> pq;
        
        dfs(root, um, 0);
        
        for (auto [_, sum]: um) {
            pq.push(sum);
            
            if (size(pq) > k) {
                pq.pop();
            }
        }
        
        if (size(pq) == k) {
            return pq.top();
        }
        
        return -1;
    }
};