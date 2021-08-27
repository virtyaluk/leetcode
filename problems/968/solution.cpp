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

enum Camera {
    Covered,
    HasCamera,
    NeedsCover
};

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int ans = 0;
        
        if (helper(root, ans) == NeedsCover) {
            ans++;
        }
        
        return ans;
    }
    
    Camera helper(TreeNode *root, int& ans) {
        if (not root) {
            return Covered;
        }
        
        Camera left = helper(root->left, ans),
            right = helper(root->right, ans);
        
        if (left == NeedsCover or right == NeedsCover) {
            ans++;
            return HasCamera;
        }
        
        if (left == HasCamera or right == HasCamera) {
            return Covered;
        }
        
        return NeedsCover;
    }
};