/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        int sum = 0;
        
        for (Node *node: tree) {
            sum += node->val;
            
            for (Node *child: node->children) {
                sum -= child->val;
            }
        }
        
        for (Node *node: tree) {
            if (node->val == sum) {
                return node;
            }
        }
        
        return NULL;
    }
};