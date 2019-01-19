/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    head, carry := &ListNode{-1, nil}, false
    dummy := head
    
    for l1 != nil || l2 != nil || carry {
        sum := 0
        
        if carry {
            sum++
        }
        
        if l1 != nil {
            sum += l1.Val
            l1 = l1.Next
        }
        
        if l2 != nil {
            sum += l2.Val
            l2 = l2.Next
        }
        
        carry = sum > 9
        sum %= 10
        
        dummy.Next = &ListNode{sum, nil}
        dummy = dummy.Next
    }
    
    return head.Next
}