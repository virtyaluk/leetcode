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
    stack<TreeNode*> path;
    vector<int> vals;
    int pos = -1;
    
    void traverseLeft(TreeNode *root) {
        for (; root; root = root->left) {
            path.push(root);
        }
    }
public:
    BSTIterator(TreeNode* root) {
        traverseLeft(root);
    }
    
    bool hasNext() {
        return pos + 1 < size(vals) or not empty(path);
    }
    
    int next() {
        if (++pos == size(vals)) {
            TreeNode *cur = path.top();
            path.pop();
            
            traverseLeft(cur->right);
            vals.push_back(cur->val);
        }
        
        return vals[pos];
    }
    
    bool hasPrev() {
        return pos > 0;
    }
    
    int prev() {
        return vals[--pos];
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */