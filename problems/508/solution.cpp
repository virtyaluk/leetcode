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
    unordered_map<int, int> m;
    int mostFreq;
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        
        traverse(root);
        
        for (auto [sum, freq]: m) {
            if (freq == mostFreq) {
                ans.push_back(sum);
            }
        }
        
        return ans;
    }
    
    int traverse(TreeNode* node) {
        if (!node) {
            return 0;
        }
        
        int sum = node->val + traverse(node->left) + traverse(node->right);
        
        m[sum]++;
        mostFreq = max(mostFreq, m[sum]);
        
        return sum;
    }
};