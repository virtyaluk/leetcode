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
    vector<int> postOrder(TreeNode* cur, int dist) {
        if (not cur) {
            return vector<int>(12);
        } else if (not cur->left and not cur->right) {
            vector<int> ans(12);
            ans[0] = 1;
            
            return ans;
        }
        
        vector<int> left = postOrder(cur->left, dist),
            right = postOrder(cur->right, dist),
            ans(12);
        
        for (int i = 0; i < 10; i++) {
            ans[i + 1] = left[i] + right[i];
        }
        
        ans[11] += left[11] + right[11];
        
        for (int i = 0; i <= dist; i++) {
            for (int j = 0; j <= dist; j++) {
                if (2 + i + j <= dist) {
                    ans[11] += left[i] * right[j];
                }
            }
        }
        
        return ans;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        return postOrder(root, distance)[11];
    }
};