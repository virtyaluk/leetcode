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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (not l1) {
            return l2;
        } else if (not l2) {
            return l1;
        }
        
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        
        while (l1 and l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            
            cur = cur->next;
        }
        
        while (l1) {
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
        }
        
        while (l2) {
            cur->next = l2;
            cur = cur->next;
            l2 = l2->next;
        }
        
        return dummy->next;
    }
};