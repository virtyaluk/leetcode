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
    int check(vector<int>& vals) {
        int ans = 0;
        vector<int> target(begin(vals), end(vals));
        unordered_map<int, int> um;
        
        sort(begin(target), end(target));
        
        for (int i = 0; i < size(vals); i++) {
            um[vals[i]] = i;
        }
        
        for (int i = 0; i < size(vals); i++) {
            if (vals[i] != target[i]) {
                ans++;
                
                int correctPos = um[target[i]];
                um[vals[i]] = correctPos;
                
                swap(vals[i], vals[correctPos]);
            }
        }
        
        return ans;
    }
    
public:
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while (not empty(q)) {
            vector<int> vals;
            
            for (int qLen = size(q); qLen > 0; qLen--) {
                TreeNode *node = q.front();
                q.pop();
                
                vals.push_back(node->val);
                
                if (node->left) {
                    q.push(node->left);
                }
                
                if (node->right) {
                    q.push(node->right);
                }
            }
            
            ans += check(vals);
        }
        
        return ans;
    }
};