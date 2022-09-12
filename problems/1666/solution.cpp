/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
private:
    Node* root = nullptr;
    
    Node* dfs(Node* node, Node* newParent) {
        Node* oldParent = node->parent;
        node->parent = newParent;
        
        if (node->left == newParent) {
            node->left = nullptr;
        }
        
        if (node->right == newParent) {
            node->right = nullptr;
        }
        
        if (node == root) {
            return node;
        }
        
        if (node->left) {
            node->right = node->left;
        }
        
        node->left = dfs(oldParent, node);
        
        return node;
    }
public:
    Node* flipBinaryTree(Node* root, Node * leaf) {
        this->root = root;
        
        return dfs(leaf, nullptr);
    }
};