# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        head = ListNode(-1)
        dummy = head
        
        while any(lists):
            cur_min, cur_i = float('inf'), -1
            
            for i in range(len(lists)):
                node = lists[i]
                
                if node and node.val <= cur_min:
                    cur_min, cur_i = node.val, i
            
            if cur_i > -1:
                dummy.next = lists[cur_i]
                dummy = dummy.next
                lists[cur_i] = lists[cur_i].next
                
        
        return head.next