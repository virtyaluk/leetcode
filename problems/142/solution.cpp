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
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> s;
        int idx = 0;
        
        while (head && head->next) {
            if (s.find(head) != s.end()) {
                return head;
            }
            
            s.insert(head);
            head = head->next;
        }
        
        return nullptr;
    }
};