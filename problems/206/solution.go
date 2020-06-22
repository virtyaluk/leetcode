package main
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    var next *ListNode = nil
    var cur *ListNode = nil
    
    for head != nil {
        cur = head.Next
        head.Next = next
        next = head
        head = cur
    }
    
    return next
}