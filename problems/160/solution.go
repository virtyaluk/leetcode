package main
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getIntersectionNode(ha, hb *ListNode) *ListNode {
    a, b := ha, hb
    
    for a != b {
        if a == nil {
            a = hb
        } else {
            a = a.Next
        }
        
        if b == nil {
            b = ha
        } else {
            b = b.Next
        }
    }
    
    return a
}

func getIntersectionNode1(ha, hb *ListNode) *ListNode {
    if ha == nil || hb == nil {
        return nil
    }
    
    cur := ha
    
    for cur.Next != nil {
        cur = cur.Next
    }
    
    cur.Next = ha
    
    slow, fast := hb, hb
    
    for fast != nil && fast.Next != nil {
        slow = slow.Next
        fast = fast.Next.Next
        
        if slow == fast {
            break
        }
    }
    
    if fast == nil || fast.Next == nil {
        cur.Next = nil
        return nil
    }
    
    slow = hb
    
    for slow != fast {
        slow = slow.Next
        fast = fast.Next
    }
    
    cur.Next = nil
    
    return slow
}