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
    bool checkEqualTree(TreeNode* root) {
        vector<int> subtreeSum;
        int totalSum = getTreeSum(root, subtreeSum);
        
        if (totalSum % 2 != 0) {
            return 0;
        }
        
        subtreeSum.pop_back();
        
        return find(begin(subtreeSum), end(subtreeSum), totalSum / 2) != end(subtreeSum);
    }
    
    int getTreeSum(TreeNode *root, vector<int>& sum) {
        if (not root) {
            return 0;
        }
        
        int subtreeSum = getTreeSum(root->left, sum) + root->val + getTreeSum(root->right, sum);
        
        sum.push_back(subtreeSum);
        
        return subtreeSum;
    }
};