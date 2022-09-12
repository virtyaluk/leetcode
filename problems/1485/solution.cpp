/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    unordered_map<Node*, NodeCopy*> m;

    NodeCopy* copyRandomBinaryTree(Node* root) {
        if (!root) {
            return NULL;
        }
        
        if (m.find(root) != m.end()) {
            return m[root];
        }
        
        NodeCopy *newNode = new NodeCopy(root->val);
        
        m[root] = newNode;
        
        newNode->left = copyRandomBinaryTree(root->left);
        newNode->right = copyRandomBinaryTree(root->right);
        newNode->random = copyRandomBinaryTree(root->random);
        
        return newNode;
    }
};