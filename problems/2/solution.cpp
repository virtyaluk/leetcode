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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1), *cur = nullptr;
        bool carry = false;
        cur = dummy;
        
        while (l1 || l2 || carry) {
            int val = carry ? 1 : 0;
            
            if (l1) {
                val += l1->val;
                l1 = l1->next;
            }
            
            if (l2) {
                val += l2->val;
                l2 = l2->next;
            }
            
            carry = val > 9;
            val %= 10;
            
            cur->next = new ListNode(val);
            cur = cur->next;
        }
        
        return dummy->next;
    }
};