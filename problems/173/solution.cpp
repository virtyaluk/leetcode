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
class BSTIterator {
private:
    stack<TreeNode*> st;
    TreeNode *root = nullptr;
public:
    BSTIterator(TreeNode* _root): root{_root} {}
    
    int next() {
        int ans = -1;
        
        if (not empty(st) or root) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            
            root = st.top();
            st.pop();
            
            ans = root->val;
            root = root->right;
        }
        
        return ans;
    }
    
    bool hasNext() {
        return not empty(st) or root;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */