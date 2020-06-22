# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        if not head:
            return None
        
        newHead = ListNode(-1, head)
        node = newHead
        
        while node.next:
            if node.next.val == val:
                node.next = node.next.next
            else:
                node = node.next
        
        return newHead.next
        