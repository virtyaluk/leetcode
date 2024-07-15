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
    void dfs(TreeNode* root, unordered_map<int, unordered_set<int>>& um, int parent = -1) {
        if (!root) {
            return;
        }
        
        if (parent != -1) {
            um[parent].insert(root->val);
            um[root->val].insert(parent);
        }
        
        dfs(root->left, um, root->val);
        dfs(root->right, um, root->val);
    }
    
public:
    int amountOfTime(TreeNode* root, int start) {
        int ans = 0;
        unordered_map<int, unordered_set<int>> um;
        unordered_set<int> visited;
        queue<int> q;
        
        dfs(root, um);
        q.push(start);
        visited.insert(start);
        
        while (not empty(q)) {
            ans++;
            
            for (int qLen = size(q); qLen > 0; qLen--) {
                int u = q.front();
                q.pop();
                
                for (const int& v: um[u]) {
                    if (not visited.count(v)) {
                        q.push(v);
                        visited.insert(v);
                    }
                }
            }
        }
        
        return ans - 1;
    }
};