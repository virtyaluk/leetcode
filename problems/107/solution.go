package main
import "fmt"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrderBottom(root *TreeNode) [][]int {
    ans := [][]int{}
    
    if root == nil {
        return ans
    }
    
    q := []*TreeNode{root}
    
    for len(q) > 0 {
        cur, qlen := []int{}, len(q)
        
        for ; qlen > 0; qlen-- {
            node := q[0]
            q = q[1:]
            
            if node != nil {
                cur = append(cur, node.Val)
                q = append(q, node.Left, node.Right)
            }
        }
        
        if len(cur) > 0 {
            ans = append(ans, cur)
        }
    }
    
    lo, hi := 0, len(ans) - 1
    
    for lo <= hi {
        ans[lo], ans[hi] = ans[hi], ans[lo]
        lo++
        hi--
    }
    
    return ans
}