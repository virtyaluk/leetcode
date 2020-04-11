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
    vector<TreeNode*> generateTrees(int n) {
        return backtrack(1, n);
    }
    
    vector<TreeNode*> backtrack(int start, int end) {
        if (start > end) {
            return {nullptr};
        }
        
        vector<TreeNode*> ans;
        
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftNodes = backtrack(start, i - 1),
                rightNodes = backtrack(i + 1, end);
            
            for (TreeNode *left: leftNodes) {
                for (TreeNode *right: rightNodes) {
                    ans.push_back(new TreeNode(i, left, right));
                }
            }
        }
        
        return ans;
    }
};