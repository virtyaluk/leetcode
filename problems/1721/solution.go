package main
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapNodes(head *ListNode, k int) *ListNode {
    cur, lo, hi := head, head, head
    
    for cur != nil {
        k--
        
        if k == 0 {
            lo = cur
        }
        
        if k < 0 {
            hi = hi.Next
        }
        
        cur = cur.Next
    }
    
    lo.Val, hi.Val = hi.Val, lo.Val
    
    return head
}