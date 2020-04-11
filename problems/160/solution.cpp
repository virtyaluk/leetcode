/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *ha, ListNode *hb) {
        ListNode *a = ha, *b = hb;
        
        while (a != b) {
            a = not a ? hb : a->next;
            b = not b ? ha : b->next;
        }
        
        return a;
    }
    
    ListNode *getIntersectionNode2(ListNode *ha, ListNode *hb) {
        if (not ha or not hb) {
            return nullptr;
        }
        
        ListNode *cur = ha, *slow = nullptr, *fast = nullptr;
        
        while (cur->next) {
            cur = cur->next;
        }
        
        cur->next = ha;
        slow = hb;
        fast = hb;
        
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                break;
            }
        }
        
        if (not fast or not fast->next) {
            cur->next = nullptr;
            return nullptr;
        }
        
        slow = hb;
        
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        cur->next = nullptr;
        
        return slow;
    }
    
    ListNode *getIntersectionNode1(ListNode *ha, ListNode *hb) {
        ListNode *ans = nullptr, *cur = ha;
        
        while (cur) {
            cur->val *= -1;
            cur = cur->next;
        }
        
        cur = hb;
        
        while (cur) {
            if (cur->val < 0) {
                ans = cur;
                break;
            }
            
            cur = cur->next;
        }
        
        cur = ha;
        
        while (cur) {
            cur->val *= -1;
            cur = cur->next;
        }
        
        return ans;
    }
};