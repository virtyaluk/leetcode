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
    ListNode* frequenciesOfElements(ListNode* head) {
        if (not head) {
            return nullptr;
        }
        
        unordered_map<int, int> freq;
        ListNode *ans = new ListNode(),
            *cur = ans;
        
        while (head) {
            freq[head->val]++;
            head = head->next;
        }
        
        for (auto [_, cnt]: freq) {
            cur->next = new ListNode(cnt);
            cur = cur->next;
        }
        
        return ans->next;
    }
};