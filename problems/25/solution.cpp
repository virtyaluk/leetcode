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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (not head or not head->next or k == 1) {
            return head;
        }
        
        ListNode *dummy = new ListNode(-1, head), *cur = dummy;
        
        for (int i = 1; head; i++) {
            if (i % k == 0) {
                cur = reverse(cur, head->next);
                head = cur->next;
            } else {
                head = head->next;
            }
        }
        
        return dummy->next;
    }
    
    ListNode* reverse(ListNode *beforeStart, ListNode *afterEnd) {
        ListNode *cur = beforeStart->next,
            *prev = beforeStart,
            *tail = cur;
        
        while (cur != afterEnd) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        beforeStart->next = prev;
        tail->next = cur;
        
        return tail;
    }
};