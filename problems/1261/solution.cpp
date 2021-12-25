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
class FindElements {
public:
    TreeNode* _root;
    set<int> s;
    FindElements(TreeNode* root) {
        _root = root;
        
        if (_root) {
            _root->val = 0;

            helper(_root);
        }
    }
    
    void helper(TreeNode* node) {
        int x = node->val;
        
        s.insert(x);
        
        if (node->left) {
            node->left->val = 2 * x + 1;
            helper(node->left);
        }
        
        if (node->right) {
            node->right->val = 2 * x + 2;
            helper(node->right);
        }
    }
    
    bool find(int target) {
        return s.find(target) != s.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */