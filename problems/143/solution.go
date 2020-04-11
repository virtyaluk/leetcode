package main
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reorderList(head *ListNode)  {
    if head == nil {
        return
    }
    
    var prev *ListNode
    slow, fast := head, head
    
    for fast != nil && fast.Next != nil {
        slow = slow.Next
        fast = fast.Next.Next
    }
    
    cur := slow
    
    for cur != nil {
        tmp := cur.Next
        cur.Next = prev
        prev = cur
        cur = tmp
    }
    
    first, second := head, prev
    
    for second.Next != nil {
        tmp := first.Next
        first.Next = second
        first = tmp
        
        tmp = second.Next
        second.Next = first
        second = tmp
    }
}