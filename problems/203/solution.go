package main
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeElements(head *ListNode, val int) *ListNode {
    newHead := &ListNode{-1, head}
    node := newHead
    
    for node.Next != nil {
        if node.Next.Val == val {
            node.Next = node.Next.Next
        } else {
            node = node.Next
        }
    }
    
    return newHead.Next
}