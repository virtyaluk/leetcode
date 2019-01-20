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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = new ListNode(-1, head), *cur;
        cur = slow;
        
        while (head) {
            head = head->next;
            
            if (n <= 0) {
                slow = slow->next;
            }
            
            n--;
        }
        
        slow->next = slow->next->next;
        
        return cur->next;
    }
    
    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        ListNode* dummy = new ListNode(), *cur = head;
        dummy->next = head;
        int len = 0;
        
        while (cur) {
            len++;
            cur = cur->next;
        }
        
        len -= n;
        cur = dummy;
        
        while (len > 0) {
            len--;
            cur = cur->next;
        }
        
        cur->next = cur->next->next;
        
        return dummy->next;
    }
};