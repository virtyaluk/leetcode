package main
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSymmetric(root *TreeNode) bool {
    return traverse(root, root)
}

func traverse(left, right *TreeNode) bool {
    if left == nil && right == nil {
        return true
    }
    
    if left == nil || right == nil {
        return false
    }
    
    return left.Val == right.Val && traverse(left.Left, right.Right) && traverse(left.Right, right.Left)
}