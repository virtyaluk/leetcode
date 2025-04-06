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
    unordered_map<TreeNode*, int> memo[2];
    
    int dfs(TreeNode* root, bool required) {
        if (root->val <= 1) {
            if (root->val == required) {
                return 0;
            }
            else {
                return 1;
            }
        }
        
        if (memo[required].find(root) != end(memo[required])) {
            return memo[required][root];
        }
        
        if (root->val == 2) {
            if (required == true) {
                return memo[required][root] = min({
                    dfs(root->left, true) + dfs(root->right, true),
                    dfs(root->left, true) + dfs(root->right, false),
                    dfs(root->left, false) + dfs(root->right, true)
                });
            }
            else {
                return memo[required][root] = dfs(root->left, false) + dfs(root->right, false);
            }
        } else if (root->val == 3) {
            if (required == false) {
                return memo[required][root] = min({
                        dfs(root->left, false) + dfs(root->right, false),
                        dfs(root->left, true) + dfs(root->right, false),
                        dfs(root->left, false) + dfs(root->right, true)
                    });
            }
            else {
                return memo[required][root] = dfs(root->left, true) + dfs(root->right, true);
            }
        } else if (root->val == 4) {
            if (required == true) {
                return memo[required][root] = min(
                    dfs(root->left, true) + dfs(root->right, false),
                    dfs(root->left, false) + dfs(root->right, true)
                );
            }
            else {
                return memo[required][root] = min(
                    dfs(root->left, true) + dfs(root->right, true),
                    dfs(root->left, false) + dfs(root->right, false)
                );
            }
        } else {
            if (required == true) {
                if (root->left) {
                    return memo[required][root] = dfs(root->left, false);
                }
                else {
                    return memo[required][root] = dfs(root->right, false);
                }
            }
            else {
                if (root->left) {
                    return memo[required][root] = dfs(root->left, true);
                }
                else {
                    return memo[required][root] = dfs(root->right, true);
                }
            }
        }
    }
public:
    int minimumFlips(TreeNode* root, bool result) {
        return dfs(root, result);
    }
};