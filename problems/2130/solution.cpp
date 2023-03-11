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
    int pairSum(ListNode* head) {
        int ans = 0;
        vector<int> l;
        
        while (head) {
            l.push_back(head->val);
            head = head->next;
        }
        
        for (int lo = 0, hi = size(l) - 1; lo < hi; lo++, hi--) {
            ans = max(ans, l[lo] + l[hi]);
        }
        
        return ans;
    }
};