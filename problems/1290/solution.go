package main
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

import "strconv"

func getDecimalValue(head *ListNode) int {
    b := ""
    
    for next := head; next != nil; next = next.Next {
        b += strconv.Itoa(next.Val)
    }
    
    i, _ := strconv.ParseInt(b, 2, 64)
    
    return int(i)
}