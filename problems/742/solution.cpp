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
class Res {
public:
    TreeNode *leaf;
    int distToLeaf, distToTarget;
    bool foundTarget;
    
    Res(TreeNode *l, int dtl, int dtt, bool ft): leaf{l}, distToLeaf{dtl}, distToTarget{dtt}, foundTarget{ft} {}
};

class Solution {
private:
    int shorthestPath = INT_MAX;
    TreeNode *shorthestLeaf = nullptr;
public:
    int findClosestLeaf(TreeNode* root, int k) {
        Res *res = dfs(root, k);
        
        return shorthestLeaf->val;
    }
    
    Res* dfs(TreeNode *root, int k) {
        Res *res = new Res(nullptr, INT_MAX, INT_MAX, false);
        
        if (not root) {
            return res;
        }
        
        Res *left = dfs(root->left, k), *right = dfs(root->right, k);
        
        if (not left->leaf and not right->leaf) {
            res->leaf = root;
            res->distToLeaf = 0;
        } else {
            res->distToLeaf = 1 + (left->distToLeaf <= right->distToLeaf ? left->distToLeaf : right->distToLeaf);
            res->leaf = left->distToLeaf <= right->distToLeaf ? left->leaf : right->leaf;
        }
        
        if (root->val == k) {
            res->foundTarget = true;
            res->distToTarget = 0;
            
            shorthestPath = res->distToLeaf;
            shorthestLeaf = res->leaf;
        } else if (left->foundTarget or right->foundTarget) {
            res->foundTarget = true;
            res->distToTarget = 1 + min(left->distToTarget, right->distToTarget);
            
            if (res->distToTarget + res->distToLeaf < shorthestPath) {
                shorthestPath = res->distToTarget + res->distToLeaf;
                shorthestLeaf = res->leaf;
            }
        }
        
        return res;
    }
};