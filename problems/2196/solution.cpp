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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode *ans = nullptr;
        unordered_map<int, TreeNode*> um;
        unordered_map<TreeNode*, TreeNode*> chToPa;
        queue<TreeNode*> q;
        
        for (const vector<int>& desc: descriptions) {
            int parent = desc[0],
                child = desc[1],
                isLeft = desc[2];
            
            if (not um.count(parent)) {
                um[parent] = new TreeNode(parent);
            }
            
            if (not um.count(child)) {
                um[child] = new TreeNode(child);
            }
            
            if (isLeft) {
                um[parent]->left = um[child];
            } else {
                um[parent]->right = um[child];
            }
            
            chToPa[um[child]] = um[parent];
        }
        
        q.push(um[descriptions.front().front()]);
        
        while (not empty(q)) {
            TreeNode *cur = q.front();
            q.pop();
            
            ans = cur;
            
            if (chToPa.count(cur)) {
                q.push(chToPa[cur]);
            }
        }
        
        return ans;
    }
};