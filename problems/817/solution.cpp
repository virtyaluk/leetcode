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
    int numComponents(ListNode* head, vector<int>& nums) {
        int ans = 0,
            cur = 0;
        unordered_set<int> us(begin(nums), end(nums));

        while (head) {
            if (us.count(head->val)) {
                cur++;
            } else {
                cur = 0;
            }

            ans += cur == 1;
            head = head->next;
        }

        return ans;
    }
};