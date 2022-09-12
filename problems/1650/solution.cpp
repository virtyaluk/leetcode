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
    Node* lowestCommonAncestor(Node* p, Node * q) {
        if (not p or not q) {
            return nullptr;
        }
        
        int pDepth = 0, qDepth = 0;
        Node *cur = p;
        
        while (cur) {
            cur = cur->parent;
            pDepth++;
        }
        
        cur = q;
        
        while (cur) {
            cur = cur->parent;
            qDepth++;
        }
        
        while (pDepth > qDepth) {
            p = p->parent;
            pDepth--;
        }
        
        while (qDepth > pDepth) {
            q = q->parent;
            qDepth--;
        }
        
        while (p != q) {
            q = q->parent;
            p = p->parent;
        }
        
        return p;
    }
};