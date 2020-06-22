package main
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func invertTree(root *TreeNode) *TreeNode {
    invert(root)
    
    return root
}

func invert(root *TreeNode) {
    if root == nil {
        return
    }
    
    invert(root.Left)
    invert(root.Right)
    
    root.Left, root.Right = root.Right, root.Left
}