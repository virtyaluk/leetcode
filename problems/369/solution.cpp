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
    ListNode* plusOne(ListNode* head) {
        head = reverse(head);
        
        ListNode *cur = head, *prev = nullptr;
        bool carry = true;
        
        while (cur) {
            cur->val += carry ? 1 : 0;
            carry = cur->val >= 10;
            cur->val %= 10;
            prev = cur;
            cur = cur->next;
        }
        
        if (carry) {
            prev->next = new ListNode(1);
        }
        
        return reverse(head);
    }
    
    ListNode* reverse(ListNode* head) {
        if (!head) {
            return head;
        }
        
        ListNode *prev = nullptr, *cur = head, *next = nullptr;
        
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        return prev;
    }
};