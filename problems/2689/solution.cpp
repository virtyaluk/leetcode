/**
 * Definition for a rope tree node.
 * struct RopeTreeNode {
 *     int len;
 *     string val;
 *     RopeTreeNode *left;
 *     RopeTreeNode *right;
 *     RopeTreeNode() : len(0), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(string s) : len(0), val(std::move(s)), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x) : len(x), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x, RopeTreeNode *left, RopeTreeNode *right) : len(x), val(""), left(left), right(right) {}
 * };
 */
class Solution {
private:
    string dfs(RopeTreeNode* node) {
        if (not node) {
            return "";
        }
        
        if (not node->left and not node->right) {
            return node->val;
        }
        
        return dfs(node->left) + dfs(node->right);
    }
    
public:
    char getKthCharacter(RopeTreeNode* root, int k) {
        return dfs(root)[k - 1];
    }
};