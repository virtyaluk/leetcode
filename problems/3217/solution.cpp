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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> us(begin(nums), end(nums));
        ListNode *ll = new ListNode(-1, head),
            *cur = ll;
        
        while (cur and cur->next) {
            if (us.count(cur->next->val)) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        
        return ll->next;
    }
};