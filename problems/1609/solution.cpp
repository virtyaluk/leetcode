class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* node = root;
        bool even = true;
        
        q.push(node);

        while (not empty(q)) {
            int qLen = size(q),
                prev = even ? INT_MIN: INT_MAX;

            while (qLen > 0) {
                node = q.front();
                q.pop();

                if ((even && (node->val % 2 == 0 || node->val <= prev)) || 
                        (!even && (node->val % 2 == 1 || node->val >= prev))) {
                    return false;
                }
                
                prev = node->val;
                
                if (node->left) {
                    q.push(node->left);
                }
                
                if (node->right) {
                    q.push(node->right);
                }
                
                qLen--;
            }
            
            even = !even;
        }
        
        return true;
    }
};