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
    int sumRootToLeaf(TreeNode* root) {
        // return bfs(root);
        // return dfs(root);
        // return dfs2(root);
        return morris(root);
    }
    
    int morris(TreeNode *root) {
        if (!root) {
            return 0;
        }
        
        int ans = 0, pathSum = 0;
        
        while (root) {
            if (root->left) {
                int shift = 1;
                TreeNode *prev = root->left;
                
                while (prev->right && prev->right != root) {
                    prev = prev->right;
                    shift++;
                }
                
                if (!prev->right) {
                    pathSum = (pathSum << 1) | root->val;
                    prev->right = root;
                    root = root->left;
                } else {
                    prev->right = nullptr;

                    if (!prev->left) {
                        ans += pathSum;
                    }
                    
                    pathSum >>= shift;
                    root = root->right;
                }
            } else {
                pathSum = (pathSum << 1) | root->val;
                
                if (!root->right) {
                    ans += pathSum;
                }
                
                root = root->right;
            }
        }
        
        return ans;
    }
    
    int dfs2(TreeNode *root) {
        if (!root) {
            return 0;
        }
        
        int ans = 0;
        stack<TreeNode*> st;
        
        st.push(root);
        
        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            
            if (node->left == node->right) {
                ans += node->val;
            }
            
            if (node->left) {
                node->left->val = (node->val << 1) | node->left->val;
                st.push(node->left);
            }
            
            if (node->right) {
                node->right->val = (node->val << 1) | node->right->val;
                st.push(node->right);
            }
        }
        
        return ans;
    }
    
    int dfs(TreeNode *root) {
        if (!root) {
            return 0;
        }
        
        int ans = 0;
        stack<TreeNode*> st;
        TreeNode *cur = root;
        
        while (!st.empty() || cur) {
            while (cur) {
                st.push(cur);
                
                if (cur->left) {
                    cur->left->val = (cur->val << 1) | cur->left->val;
                }
                
                cur = cur->left;
            }
            
            cur = st.top();
            st.pop();
            
            if (!cur->left && !cur->right) {
                ans += cur->val;
            }
            
            if (cur->right) {
                cur->right->val = (cur->val << 1) | cur->right->val;
            }
            
            cur = cur->right;
        }
        
        return ans;
    }
    
    int bfs(TreeNode *root) {
        if (!root) {
            return 0;
        }
        
        int ans = 0;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            
            if (!node->left && !node->right) {
                ans += node->val;
                continue;
            }
            
            if (node->left) {
                node->left->val = (node->val << 1) | node->left->val;
                q.push(node->left);
            }
            
            if (node->right) {
                node->right->val = (node->val << 1) | node->right->val;
                q.push(node->right);
            }
        }
        
        return ans;
    }
};