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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ans;
        stack<TreeNode*> st;
        int idx = 0;
        
        st.push(root);
        
        while (not st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            
            if (node->val != voyage[idx]) {
                ans = {-1};
                break;
            }
            
            idx++;
            
            if (node->left and node->left->val != voyage[idx]) {
                swap(node->left, node->right);
                ans.push_back(node->val);
            }
            
            if (node->right) {
                st.push(node->right);
            }
            
            if (node->left) {
                st.push(node->left);
            }
        }
         
        return ans;
    }
};