using it = vector<int>::iterator;

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, size(nums));
    }
    
    TreeNode* helper(vector<int>& nums, int lo, int hi) {
        if (lo == hi) {
            return nullptr;
        }
        
        int maxIdx = getMaxIdx(nums, lo, hi);
        TreeNode *node = new TreeNode(nums[maxIdx]);
        node->left = helper(nums, lo, maxIdx);
        node->right = helper(nums, maxIdx + 1, hi);
        
        return node;
    }
    
    int getMaxIdx(vector<int>& nums, int lo, int hi) {
        int idx = lo;
        
        for (int i = lo; i < hi; i++) {
            if (nums[i] > nums[idx]) {
                idx = i;
            }
        }
        
        return idx;
    }
};