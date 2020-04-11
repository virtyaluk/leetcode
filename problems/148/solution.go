package main
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func sortList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    
    mid := findMid(head)
    left, right := sortList(head), sortList(mid)
    
    return merge(left, right)
}

func merge(left, right *ListNode) *ListNode {
    dummy := &ListNode{}
    tail := dummy
    
    for left != nil && right != nil {
        if left.Val < right.Val {
            tail.Next = left
            left = left.Next
        } else {
            tail.Next = right
            right = right.Next
        }
        
        tail = tail.Next
    }
    
    if left != nil {
        tail.Next = left
    } else {
        tail.Next = right
    }
    
    return dummy.Next
}

func findMid(node *ListNode) *ListNode {
    var midPrev *ListNode = nil
    
    for node != nil && node.Next != nil {
        if (midPrev != nil) {
            midPrev = midPrev.Next
        } else {
            midPrev = node
        }
        
        node = node.Next.Next
    }
    
    mid := midPrev.Next
    midPrev.Next = nil
    
    return mid
}