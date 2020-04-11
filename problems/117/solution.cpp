/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return NULL;
        }
        
        Node *leftMost = root;
        
        while (leftMost) {
            Node *head = leftMost, *prev = NULL;
            
            while (head) {
                if (head->left && head->right) {
                    if (prev) {
                        prev->next = head->left;
                    } else {
                        leftMost = head->left;
                    }
                    
                    head->left->next = head->right;
                    prev = head->right;
                } else if (head->left && !head->right) {
                    if (prev) {
                        prev->next = head->left;
                    } else {
                        leftMost = head->left;
                    }
                    
                    prev = head->left;
                } else if (!head->left && head->right) {
                    if (prev) {
                        prev->next = head->right;
                    } else {
                        leftMost = head->right;
                    }
                    
                    prev = head->right;
                } else {
                    if (!prev) {
                        leftMost = NULL;
                    }
                }
                
                head = head->next;
            }
        }
        
        return root;
    }
};