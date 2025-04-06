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
private:
    TreeNode* construct(vector<int>& pre, vector<int>& post, int& preIdx, int& postIdx) {
        TreeNode* root = new TreeNode(pre[preIdx++]);

        if (root->val != post[postIdx]) {
            root->left = construct(pre, post, preIdx, postIdx);
        }

        if (root->val != post[postIdx]) {
            root->right = construct(pre, post, preIdx, postIdx);
        }

        postIdx++;

        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int pre = 0,
            post = 0;
        
        return construct(preorder, postorder, pre, post);
    }
};