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
    TreeNode* balanceBST(TreeNode* root) {
        TreeNode *pseudoRoot = new TreeNode(-1, nullptr, root);
        int nodesCount = flattenTree(pseudoRoot), // nodes count
            treeHeight = log2(nodesCount + 1), // tree height h = (2^h) - 1 = log2(h + 1)
            balancedTreeNodesCount = pow(2, treeHeight) - 1;
    
        // perform x right rotations to cover up the excess
        compressTree(pseudoRoot, nodesCount - balancedTreeNodesCount);
        
        for (int i = balancedTreeNodesCount / 2; i > 0; i /= 2) {
            compressTree(pseudoRoot, i);
        }
        
        return pseudoRoot->right;
    }
    
    TreeNode* rightRotate(TreeNode *node) {
        auto *pseudoRoot = node->left;
        
        node->left = pseudoRoot->right;
        pseudoRoot->right = node;
        
        return pseudoRoot;
    }
    
    // flatten the tree and count nodes
    int flattenTree(TreeNode *root) {
        int nodesCount = 0;
        TreeNode *pseudoRoot = root->right;
        
        while (pseudoRoot) {
            if (pseudoRoot->left) {
                // do the right rotations
                pseudoRoot = rightRotate(pseudoRoot);
                root->right = pseudoRoot;
            } else {
                nodesCount++;
                root = pseudoRoot;
                pseudoRoot = pseudoRoot->right;
            }
        }
        
        return nodesCount;
    }
    
    TreeNode* leftRotate(TreeNode *node) {
        auto *pseudoRoot = node->right;
        
        node->right = pseudoRoot->left;
        pseudoRoot->left = node;
        
        return pseudoRoot;
    }
    
    void compressTree(TreeNode *root, int numRotations) {
        TreeNode *pseudoRoot = root->right;
        
        while (numRotations-- > 0) {
            root->right = pseudoRoot->right;
//             pseudoRoot = leftRotate(pseudoRoot);
            
//             root = pseudoRoot;
//             pseudoRoot = pseudoRoot->right;
            root = leftRotate(pseudoRoot);
            pseudoRoot = root->right;
        }
    }
};