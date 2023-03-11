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
    ListNode* sortLinkedList(ListNode* head) {
        ListNode * prev_node = head, * curr_node = head->next;

        while  (curr_node != nullptr) {
            if (curr_node->val < 0) {
                prev_node->next = curr_node->next;
                curr_node->next = head;
                head = curr_node;
                curr_node = prev_node;
            }

            prev_node = curr_node;
            curr_node = curr_node->next;
        }

        return head;
    }
};