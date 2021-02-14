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
    TreeNode *head = nullptr;
    bool forward = false;

public:
    BSTIterator(TreeNode *root, bool forward): head{root}, forward{forward} {}
    
    bool hasNext() {
        return head or not empty(st);
    }
    
    int next() {
        while (head or not empty(st)) {
            if (head) {
                st.push(head);
                head = forward ? head->left : head->right;
            } else {
                head = st.top();
                st.pop();
                
                int val = head->val;
                head = forward ? head->right : head->left;

                return val;
            }
        }
        
        return -1;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (not root) {
            return false;
        }
        
        BSTIterator forward(root, true),
            backward(root, false);
        
        for (int i = forward.next(), j = backward.next(); i < j;) {
            int sum = i + j;
            
            if (sum == k) {
                return true;
            } else if (sum < k) {
                i = forward.next();
            } else {
                j = backward.next();
            }
        }
        
        return false;
    }
};