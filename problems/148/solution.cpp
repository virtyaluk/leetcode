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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* mid = findMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        
        return merge(left, right);
    }
    
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (left && right) {
            if (left->val < right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            
            tail = tail->next;
        }
        
        tail->next = left ? left : right;
        
        return dummy.next;
    }
    
    ListNode* findMid(ListNode* node) {
        ListNode* midPrev = nullptr;
        
        while (node && node->next) {
            midPrev = midPrev ? midPrev->next : node;
            node = node->next->next;
        }
        
        ListNode* mid = midPrev->next;
        midPrev->next = nullptr;
        
        return mid;
    }
};