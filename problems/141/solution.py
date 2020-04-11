# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if not head or not head.next:
            return False
        
        slow, fast = head, head.next
        
        while fast.next and fast.next.next and fast != slow:
            slow = slow.next
            fast = fast.next.next
        
        return slow == fast