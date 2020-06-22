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
    bool isPalindrome(ListNode* head) {
        if (!head) {
            return true;
        }
        
        ListNode *middle = findMiddle(head);
        ListNode *secondHalf = reverse(middle->next);
        
        bool ans = true;
        
        while (ans && secondHalf) {
            ans = head->val == secondHalf->val;
            
            head = head->next;
            secondHalf = secondHalf->next;
        }
        
        return ans;
    }
    
    ListNode* findMiddle(ListNode* node) {
        ListNode *slow = node, *fast = node;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* reverse(ListNode* node) {
        ListNode *cur = node, *prev = NULL;
        
        while (cur) {
            ListNode *tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        
        return prev;
    }
};