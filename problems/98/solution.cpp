typedef long long int ll;

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
    bool isValidBST(TreeNode* root) {
        TreeNode *prev = nullptr;
        stack<TreeNode*> st;
        
        while (not empty(st) or root) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            
            root = st.top();
            st.pop();
            
            if (prev and root->val <= prev->val) {
                return false;
            }
            
            prev = root;    
            root = root->right;
        }
        
        return true;
    }
    
    bool isValidBST1(TreeNode* root) {
        bool ans = true;
        
        helper(root, ans);
        
        return ans;
    }
    
    pair<ll, ll> helper(TreeNode *root, bool& ans) { // pair<min, max>
        if (not root) {
            return {(ll) 2 * INT_MAX, (ll) 2 * INT_MIN};
        }
        
        if (not ans) {
            return {(ll) 2 * INT_MAX, (ll) 2 *INT_MIN};
        }
        
        auto [leftMin, leftMax] = helper(root->left, ans);
        auto [rightMin, rightMax] = helper(root->right, ans);
        
        if (not (root->val > leftMax and root->val < rightMin)) {
            ans = false;
        }
        
        return {min((ll) root->val, leftMin), max((ll) root->val, rightMax)};
    }
};