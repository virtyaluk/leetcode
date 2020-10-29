package main
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var ans []int
var maxCount int
var prevNum int
var curCount int

func findMode(root *TreeNode) []int {
    ans, maxCount, prevNum, curCount = []int{}, 0, -1, 0
    
    dfs(root)
    
    return ans
}

func dfs(node *TreeNode) {
    if node == nil {
        return
    }
    
    dfs(node.Left)
    
    if node.Val == prevNum {
        curCount++
    } else {
        curCount = 1
    }
    
    if curCount == maxCount {
        ans = append(ans, node.Val)
    } else if curCount > maxCount {
        ans = []int{node.Val}
        maxCount = curCount
    }
    
    prevNum = node.Val
    
    dfs(node.Right)
}