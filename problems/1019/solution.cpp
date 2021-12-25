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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> st;
        head = reverseList(head);
        
        while (head) {
            while (not st.empty() and st.top() <= head->val) {
                st.pop();
            }
            
            ans.push_back(st.empty() ? 0 : st.top());
            st.push(head->val);
            head = head->next;
        }
        
        reverse(begin(ans), end(ans));
        
        return ans;
    }
    
    ListNode* reverseList(ListNode *head) {
        if (not head) {
            return head;
        }
        
        ListNode *cur = nullptr;
        
        while (head) {
            ListNode *tmp = head->next;
            head->next = cur;
            cur = head;
            head = tmp;
        }
        
        return cur;
    }
};


// 1 -> 2 -> 3 ->
// 2 -> 1 -> 3