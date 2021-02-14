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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);
        ListNode *cur = head;
        int llSize = 0, partSize = 0, nodesLeft = 0;
        auto it = begin(ans);
        
        while (cur) {
            llSize++;
            cur = cur->next;
        }
        
        partSize = llSize / k;
        nodesLeft = llSize - (partSize * k);
        cur = head;
        
        do {
            int partCurSize = partSize + (nodesLeft > 0 ? 1 : 0);
            *it = cur;
            
            while (cur and partCurSize--) {
                // cout << partCurSize << ", " << cur->val << endl;
                ListNode *next = cur->next;
                
                if (not partCurSize) {
                    cur->next = nullptr;
                }
                
                cur = next;
            }
            
            nodesLeft--;
            it++;
        } while (cur);
        
        // cout << llSize << ", " << partSize << ", " << nodesLeft << endl;
        
        return ans;
    }
};