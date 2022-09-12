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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* node = new ListNode(0, head);
        
        while (node && node->next) {
            for (int i = 0; i < m; i++) {
                if (node) {
                    node = node->next;
                } else {
                    break;
                }
            }
            
            for (int j = 0; j < n; j++) {
                if (node && node->next) {
                    node->next = node->next->next;
                } else {
                    break;
                }
            }
        }
        
        return head;
    }
};