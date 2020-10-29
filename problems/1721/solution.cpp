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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *cur = head, *lo = head, *hi = head;
        
        while (cur) {
            k--;
            
            if (k == 0) {
                lo = cur;
            }
            
            if (k < 0) {
                hi = hi->next;
            }
            
            // cout << k << ": " << cur->val << endl;
            
            cur = cur->next;
        }
        
        // cout << "lo: " << lo->val << endl;
        // cout << "hi: " << hi->val << endl;
        
        swap(lo->val, hi->val);
        
        // cout << "***" << endl;
        
        return head;
    }
    
    ListNode* swapNodes1(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1, head), *first = NULL;
        int n = 0;
        
        while (head) {
            n++;
            
            if (n == k) {
                first = head;
            }
            
            head = head->next;
        }
        
        n -= k + 1;
        head = dummy->next;
        
        while (n >= 0 && head) {
            n--;
            head = head->next;
        }
        
        swap(first->val, head->val);
        
        return dummy->next;
    }
};