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
    TreeNode* recoverFromPreorder(string traversal) {
        unordered_map<int, TreeNode*> cache;
        int pos = 0, n = size(traversal);
        
        while (pos < n) {
            int depth = 0, val = 0;
            
            while (pos < n and traversal[pos] == '-') {
                depth++;
                pos++;
            }
            
            while (pos < n and isdigit(traversal[pos])) {
                val = val * 10 + (traversal[pos++] - '0');
            }
            
            TreeNode *node = new TreeNode(val);
            cache[depth] = node;
            
            if (not cache.count(depth - 1)) {
                continue;
            }
            
            if (not cache[depth - 1]->left) {
                cache[depth - 1]->left = node;
            } else {
                cache[depth - 1]->right = node;
            }
        }
        
        return cache[0];
    }
};