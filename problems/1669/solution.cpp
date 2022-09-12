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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *dummy = new ListNode(-1, list1), *middle = NULL;
        
        for (a--, b--; b >= 0; a--, b--) {
            if (a == 0) {
                middle = list1;
            }
            
            list1 = list1->next;
        }
        
        middle->next = list2;
        
        while (list2 && list2->next) {
            list2 = list2->next;
        }
        
        list2->next = list1->next;
        
        return dummy->next;
    }
};