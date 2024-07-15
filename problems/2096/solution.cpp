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
    bool findPath(TreeNode* node, int target, string& path) {
        if (not node) {
            return false;
        }
        
        if (node->val == target) {
            return true;
        }
        
        path.push_back('L');
        
        if (findPath(node->left, target, path)) {
            return true;
        }
        
        path.pop_back();
        path.push_back('R');
        
        if (findPath(node->right, target, path)) {
            return true;
        }
        
        path.pop_back();
        
        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string ans, startPath, destPath;
        int pathLength = 0;
        
        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);
        
        while (pathLength < size(startPath) and pathLength < size(destPath) and startPath[pathLength] == destPath[pathLength]) {
            pathLength++;
        }
        
        for (int i = 0; i < size(startPath) - pathLength; i++) {
            ans.push_back('U');
        }
        
        for (int i = pathLength; i < size(destPath); i++) {
            ans.push_back(destPath[i]);
        }
        
        return ans;
    }
};