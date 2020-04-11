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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (not head or left == right) {
            return head;
        }
        
        ListNode *dummy = new ListNode(-1, head),
            *prev = dummy,
            *cur = head,
            *reversed = nullptr;
        
        for (int i = 1; i < left; i++) {
            prev = cur;
            cur = cur->next;
        }
        
        // cout << "prev: " << prev->val << ", cur: " << cur->val << endl;
        
        for (int i = 1; i < right - left + 1; i++) {
            ListNode *next = cur->next;
            cur->next = reversed;
            reversed = cur;
            cur = next;
        }
        
        prev->next->next = cur->next;
        cur->next = reversed;
        prev->next = cur;
        
        return dummy->next;
    }
};