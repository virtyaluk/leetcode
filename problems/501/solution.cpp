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
    int maxCount = 0, curVal = INT_MIN, curCount = 0;
    
    void mode(int val, vector<int>& ans) {
        cout << "val: " << val << endl;
        
        if (val != curVal) {
            curVal = val;
            curCount = 0;
        }
        
        curCount++;
        
        if (curCount == maxCount) {
            ans.push_back(val);
        } else if (curCount > maxCount) {
            maxCount = curCount;
            
            ans.clear();
            ans.push_back(val);
        }
    }
    
public:
    vector<int> findMode(TreeNode* root) {
        if (not root) {
            return {};
        }
        
        vector<int> ans;
        
        dfs(root, ans);
        
        return ans;
    }
    
    void dfs(TreeNode *root, vector<int>& ans) {
        if (not root) {
            return;
        }
        
        dfs(root->left, ans);
        
        mode(root->val, ans);
        
        dfs(root->right, ans);
    }
};