package main
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var lastSum int

func bstToGst(root *TreeNode) *TreeNode {
    lastSum = 0
    
    dfs(root)
    
    return root
}

func dfs(node *TreeNode) {
    if node == nil {
        return
    }
    
    dfs(node.Right)
    
    lastSum += node.Val
    node.Val = lastSum
    
    dfs(node.Left)
}