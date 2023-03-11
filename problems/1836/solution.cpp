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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        ListNode *cur = new ListNode(),
            *tmp = head;
        unordered_map<int, int> freq;
        
        cur->next = head;
        
        while (tmp) {
            freq[tmp->val]++;
            tmp = tmp->next;
        }
        
        tmp = cur;
        
        while (tmp->next) {
            if (freq[tmp->next->val] != 1) {
                tmp->next = tmp->next->next;
            } else {
                tmp = tmp->next;
            }
        }
        
        return cur->next;
    }
};