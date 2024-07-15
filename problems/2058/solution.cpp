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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> idxs;
        int idx = 1,
            prev = head->val,
            minDistance = INT_MAX;
        head = head->next;
        
        while (head and head->next) {
            if ((head->val > prev and head->val > head->next->val) or (head->val < prev and head->val < head->next->val)) {
                idxs.push_back(idx);
            }
            
            prev = head->val;
            head = head->next;
            idx++;
        }
        
        if (size(idxs) < 2) {
            return {-1, -1};
        }
        
        for (int i = 1; i < size(idxs); i++) {
            minDistance = min(minDistance, idxs[i] - idxs[i - 1]);
        }
        
        return {minDistance, idxs.back() - idxs.front()};
    }
};