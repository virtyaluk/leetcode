package main
var ans []int

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func preorderTraversal(root *TreeNode) []int {
    ans = []int{}
    
    if root == nil {
        return ans
    }
    
    traverse(root)
    
    return ans
}

func traverse(node *TreeNode) {
    if node == nil {
        return
    }
    
    ans = append(ans, node.Val)
    
    traverse(node.Left)
    traverse(node.Right)
}