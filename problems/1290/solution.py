# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        b = ''
        n = head
        
        while n:
            b += str(n.val)
            n = n.next
        
        return int(b, 2)