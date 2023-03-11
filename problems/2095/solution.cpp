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
    ListNode* deleteMiddle(ListNode* head) {
        if (not head->next) {
            return nullptr;
        }
        
        ListNode *slow = head,
            *fast = head->next->next;
        
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = slow->next ? slow->next->next : nullptr;
        
        return head;
    }
};