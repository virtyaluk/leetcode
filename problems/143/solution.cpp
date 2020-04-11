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
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev = nullptr, *cur = nullptr;
        
        // find middle point
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // reverse 2nd half
        cur = slow;
        
        while (cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        // connect nodes
        while (prev->next) {
            ListNode *headNext = head->next, *prevNext = prev->next;
            head->next = prev;
            prev->next = headNext;
            head = headNext;
            prev = prevNext;
        }
    }
};