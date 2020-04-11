package main
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func buildTree(inorder []int, postorder []int) *TreeNode {
    if len(inorder) == 0 && len(postorder) == 0 {
        return nil
    }
    
    idx, val := 0, postorder[len(postorder) - 1]
    
    for inorder[idx] != val {
        idx++
    }
    
    return &TreeNode{
        val,
        buildTree(inorder[:idx], postorder[:idx]),
        buildTree(inorder[idx + 1:], postorder[idx:len(postorder) - 1]),
    }
}