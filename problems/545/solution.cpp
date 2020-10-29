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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (not root) {
            return {};
        }
        
        vector<int> ans = {root->val};
        
        traverseLeftBoundary(root->left, ans);
        traverseBottomBoundary(root->left, ans);
        traverseBottomBoundary(root->right, ans);
        traverseRightBoundary(root->right, ans);
        
        return ans;
    }
    
    void traverseLeftBoundary(TreeNode* root, vector<int>& boundary) {
        if (not root) {
            return;
        }
        
        if (root->left) {
            boundary.push_back(root->val);
            traverseLeftBoundary(root->left, boundary);
        } else if (root->right) {
            boundary.push_back(root->val);
            traverseLeftBoundary(root->right, boundary);
        }
    }
    
    void traverseRightBoundary(TreeNode* root, vector<int>& boundary) {
        if (not root) {
            return;
        }
        
        if (root->right) {
            traverseRightBoundary(root->right, boundary);
            boundary.push_back(root->val);
        } else if (root->left) {
            traverseRightBoundary(root->left, boundary);
            boundary.push_back(root->val);
        }
    }
    
    void traverseBottomBoundary(TreeNode* root, vector<int>& boundary) {
        if (not root) {
            return;
        }
        
        if (not root->left and not root->right) {
            boundary.push_back(root->val);
        }
        
        traverseBottomBoundary(root->left, boundary);
        traverseBottomBoundary(root->right, boundary);
    }
};