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
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int depth = getDepth(root);
        
        if (depth == 0) {
            return 1;
        }
        
        int lo = 1, hi = pow(2, depth) - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (checkNode(root, depth, mid)) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return pow(2, depth) - 1 + lo;
    }
    
    bool checkNode(TreeNode *root, int depth, int idx) {
        int lo = 0, hi = pow(2, depth) - 1;
        
        for (int i = 0; i < depth; i++) {
            int mid = lo + (hi - lo) / 2;
            
            if (idx <= mid) {
                root = root->left;
                hi = mid - 1;
            } else {
                root = root->right;
                lo = mid + 1;
            }
        }
        
        return root != nullptr;
    }
    
    int getDepth(TreeNode* root) {
        int depth = -1;
        
        while (root) {
            depth++;
            root = root->left;
        }
        
        return depth;
    }
};