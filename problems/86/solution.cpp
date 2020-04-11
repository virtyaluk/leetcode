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
    ListNode* partition(ListNode* head, int x) {
        ListNode *lt = new ListNode(-1), *gt = new ListNode(-1), *curLt = nullptr, *curGt = nullptr;
        curLt = lt, curGt = gt;
        
        while (head) {
            if (head->val < x) {
                curLt->next = head;
                curLt = curLt->next;
            } else {
                curGt->next = head;
                curGt = curGt->next;
            }
            
            head = head->next;
        }
        
        curGt->next = nullptr;
        curLt->next = gt->next;
        
        return lt->next;
    }
};