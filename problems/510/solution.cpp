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
public:
    Node* inorderSuccessor(Node* node) {
        if (not node) {
            return nullptr;
        }
        
        if (node->right) {
            node = node->right;
            
            while (node->left) {
                node = node->left;
            }
            
            return node;
        }
        
        while (node->parent and node->parent->right == node) {
            node = node->parent;
        }
        
        return node->parent;
    }
};