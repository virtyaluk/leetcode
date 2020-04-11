package main
const MaxInt = int(^uint(0) >> 1)
const MinInt = -MaxInt - 1
var prev int

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isValidBST(root *TreeNode) bool {
    prev = MinInt
    
    if root != nil {
        return inorder(root)
    }
    
    return true
}

func inorder(node *TreeNode) bool {
    if node.Left != nil && !inorder(node.Left) {
        return false
    }

    if node.Val <= prev {
        return false
    }

    prev = node.Val

    if node.Right != nil && !inorder(node.Right) {
        return false
    }

    return true
}