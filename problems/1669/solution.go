package main
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeInBetween(list1 *ListNode, a int, b int, list2 *ListNode) *ListNode {
    dummy, mid := &ListNode{-1, list1}, &ListNode{}
    a--
    b--
    
    for b >= 0 {
        if a == 0 {
            mid = list1
        }
        
        list1 = list1.Next
        a--
        b--
    }
    
    mid.Next = list2
    
    for list2 != nil && list2.Next != nil {
        list2 = list2.Next
    }
    
    list2.Next = list1.Next
    
    return dummy.Next
}