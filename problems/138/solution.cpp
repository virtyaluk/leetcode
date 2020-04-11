/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (not head) {
            return head;
        }
        
        Node *cur = head;
        
        // insert new nodes
        while (cur) {
            Node *next = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = next;
            cur = next;
        }
        
        cur = head;
        
        // update random pointer
        while (cur) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }

            cur = cur->next->next;
        }
        
        // disconnect the nodes of new and old lists
        Node *newHead = head->next,
            *oldList = head,
            *newList = head->next;
        
        while (oldList) {
            oldList->next = oldList->next->next;
            newList->next = newList->next ? newList->next->next : nullptr;
            
            oldList = oldList->next;
            newList = newList->next;
        }
        
        return newHead;
    }
};