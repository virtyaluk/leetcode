/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(), *curr = head, *prevNode = nullptr, *nextNode = nullptr;
        
        while (curr) {
            prevNode = dummy;
            nextNode = dummy->next;
            
            while (nextNode) {
                if (curr->val < nextNode->val) {
                    break;
                }
                
                prevNode = nextNode;
                nextNode = nextNode->next;
            }
            
            ListNode* next = curr->next;
            
            prevNode->next = curr;
            curr->next = nextNode;
            
            curr = next;
        }
        
        return dummy->next;
    }
};