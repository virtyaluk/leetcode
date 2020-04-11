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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode *h = nullptr;
    
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *node = head;
        int size = 0;
        
        while (node) {
            size++;
            node = node->next;
        }
        
        h = head;
        
        return build1(0, size - 1);
    }
    
    TreeNode* build1(int lo, int hi) {
        if (lo > hi) {
            return nullptr;
        }
        
        int mid = lo + (hi - lo) / 2;
        
        TreeNode *left = build1(lo, mid - 1),
            *node = new TreeNode(h->val);
        
        h = h->next;
        
        TreeNode *right = build1(mid + 1, hi);
        node->left = left;
        node->right = right;
        
        return node;
    }
    
    TreeNode* sortedListToBST1(ListNode* head) {
        vector<int> nums;
        
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        
        return build(nums, 0, nums.size() - 1);
    }
    
    TreeNode *build(const vector<int>& nums, int lo, int hi) {
        if (lo > hi) {
            return nullptr;
        }
        
        int mid = lo + (hi - lo) / 2;
        
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = build(nums, lo, mid - 1);
        node->right = build(nums, mid + 1, hi);
        
        return node;
    }
};