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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode(-1), *cur = head;
        auto cmp = [](ListNode *left, ListNode *right) {
            return left->val > right->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        
        for (ListNode *list: lists) {
            if (not list) {
                continue;
            }
            
            pq.push(list);
        }
        
        while (not empty(pq)) {
            cur->next = pq.top();
            cur = cur->next;
            
            if (pq.top()->next) {
                pq.push(pq.top()->next);
            }
            
            pq.pop();
        }
        
        return head->next;
    }
};