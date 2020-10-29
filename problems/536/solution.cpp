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
    TreeNode* str2tree(string s) {
        if (empty(s)) {
            return nullptr;
        }
        
        int pos = 0;
        s = '(' + s + ')';
        
        return helper(s, pos);
    }
    
    TreeNode *helper(string& s, int& pos) {
        if (pos >= size(s) or s[pos] != '(') {
            return nullptr;
        }
        
        pos++;
        int num = 0, neg = 1;
        
        if (s[pos] == '-') {
            neg = -1;
            pos++;
        }
        
        while (isdigit(s[pos])) {
            num = num * 10 + (s[pos++] - '0');
        }
        
        TreeNode *node = new TreeNode(num * neg);
        node->left = helper(s, pos);
        node->right = helper(s, pos);
        
        pos++;
        
        return node;
    }
};