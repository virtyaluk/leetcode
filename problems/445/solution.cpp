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
        ListNode* ans = NULL;
        bool carry = false;
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        while (l1 || l2 || carry) {
            int cur = carry ? 1: 0;
            
            if (l1) {
                cur += l1->val;
                l1 = l1->next;
            }
            
            if (l2) {
                cur += l2->val;
                l2 = l2->next;
            }
            
            carry = cur >= 10;
            
            ListNode* node = new ListNode(cur % 10);
            node->next = ans;
            ans = node;
        }
        
        return ans;
    }
    
    ListNode* reverse(ListNode* node) {
        if (!node) {
            return NULL;
        }
        
        ListNode* ans = NULL;
        
        while (node) {
            ListNode* tmp = node->next;
            node->next = ans;
            ans = node;
            node = tmp;
        }
        
        return ans;
    }
};