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
    unordered_map<int, vector<TreeNode*>> dp;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        
        if (not empty(dp[n])) {
            return dp[n];
        }
        
        if (n == 1) {
            ans.push_back(new TreeNode());
        } else {
            for (int i = 1; i < n; i += 2) {
                for (TreeNode *leftNode: allPossibleFBT(i)) {
                    for (TreeNode *rightNode: allPossibleFBT(n - i - 1)) {
                        TreeNode *node = new TreeNode(0, leftNode, rightNode);
                        
                        ans.push_back(node);
                    }
                }
            }
        }
        
        return dp[n] = ans;
    }
};