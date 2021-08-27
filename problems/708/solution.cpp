/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* newNode = new Node(insertVal);
        
        if (!head) {
            newNode->next = newNode;

            return newNode;
        }
        
        Node* cur = head;
        
        while (true) {
            if (cur->val <= insertVal && insertVal <= cur->next->val) {
                break;
            }
            
            if (cur->val > cur->next->val) {
                if (cur->val <= insertVal && insertVal >= cur->next->val) {
                    break;
                } else if (cur->val >= insertVal && insertVal <= cur->next->val) {
                    break;
                }
            }
            
            cur = cur->next;
            
            if (cur == head) {
                break;
            }
        }
        
        newNode->next = cur->next;
        cur->next = newNode;
        
        return head;
    }
};