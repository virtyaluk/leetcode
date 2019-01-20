# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        node = ListNode(0)
        tracker = node
        
        while l1 and l2:
            val = None
            
            if l1.val <= l2.val:
                val = l1.val
                l1 = l1.next
            else:
                val = l2.val
                l2 = l2.next
            
            tracker.next = ListNode(val)
            tracker = tracker.next
        
        tracker.next = l1 if l1 else l2
        
        return node.next