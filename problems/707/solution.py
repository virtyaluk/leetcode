class Node:
    def __init__(self, val, nxt = None):
        self.val = val
        self.next = nxt

class MyLinkedList:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.head = None
    
    def helper(self, node):
        pass
        # while node:
        #     print(node.val)
        #     node = node.next
        

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        n = self.head
        
        while n.next and index > 0:
            n = n.next
            index -= 1
            
        # print(n.val, index)
            
        if index != 0:
            return -1

        return n.val
        

    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        nh = Node(val, self.head)
        self.head = nh
        
        # print('addAtHead')
        # print(self.helper(self.head))
        

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        n = self.head
        
        while n.next:
            n = n.next
        
        nt = Node(val)
        n.next = nt
        
        # print('addAtTail')
        # print(self.helper(self.head))

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        if not index:
            self.addAtHead(val)
            
            return
        
        n = self.head
        index -= 1

        while n.next and index > 0:
            n = n.next
            index -= 1

        if index != 0:
            return

        nn = Node(val, n.next)
        n.next = nn
        
        # print('addAtIndex', index, val)
        # print(self.helper(self.head))

    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        if not index:
            self.head = self.head.next
            
            return
        
        n = self.head
        index -= 1

        while n.next and index > 0:
            n = n.next
            index -= 1
            
        if index != 0:
            return

        n.next = n.next.next if n.next else None
        
        # print('deleteAtIndex', index)
        # print(self.helper(self.head))


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)