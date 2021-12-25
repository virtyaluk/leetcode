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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummy = new ListNode(-1, head);
        unordered_map<int, ListNode*> um;
        int curSum = 0;
        
        um[0] = dummy;
        
        while (head) {
            curSum += head->val;
            
            if (um.count(curSum)) {
                ListNode *prev = um[curSum]->next;
                int prevSum = curSum;
                
                while (prev != head) {
                    prevSum += prev->val;
                    um.erase(prevSum);
                    prev = prev->next;
                }
                
                um[curSum]->next = head->next;
            } else {
                um[curSum] = head;
            }
            head = head->next;
        }
        
        return dummy->next;
    }
};


/*

[ 1, 2,-3, 3, 1, 1, 2,-3, 3, 1]
[0, 1, 3, 0, 3, 4, 5, 7, 4, 7, 8]

[ 1, 2, 3,-5, 6, 1,-7, 8]
[0, 1, 3, 6, 1, 7, 8, 1, 9]

[ 1, 3, 2,-3,-2, 5, 5,-5, 1]
[0, 1, 4, 6, 3, 1, 6, 11,6, 7]
*/
