/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
    dummy, prev := &ListNode{-1, nil}, &ListNode{}
    dummy.Next = head
    prev = dummy
    
    for head != nil && head.Next != nil {
        first, second := head, head.Next
        
        first.Next = second.Next
        second.Next = first
        prev.Next = second
        
        prev = first
        head = first.Next
    }
    
    return dummy.Next
}