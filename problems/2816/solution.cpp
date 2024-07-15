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
private:
    tuple<int, ListNode*> dfs(ListNode* node) {
        if (not node) {
            return {0, nullptr};
        }
        
        auto [carry, nextNode] = dfs(node->next);
        
        int newVal = node->val * 2 + carry;
        
        node->val = newVal % 10;
        
        return {newVal / 10, node};
    }
public:
    ListNode* doubleIt(ListNode* head) {
        auto [carry, node] = dfs(head);
        
        if (carry) {
            return new ListNode(carry, node);
        }
        
        return node;
    }
};