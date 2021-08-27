package main
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isCousins(root *TreeNode, x int, y int) bool {
    if root == nil {
        return false
    }
    
    xExists, xDepth, xParent := findDepthAndParent(root, x, 0, nil)
    yExists, yDepth, yParent := findDepthAndParent(root, y, 0, nil)
    
    return xExists && yExists && xDepth == yDepth && xParent != yParent
}

func findDepthAndParent(node *TreeNode, val int, k int, parent *TreeNode) (bool, int, *TreeNode) {
    if node == nil {
        return false, 0, nil
    }
    
    k++
    
    if node.Val == val {
        return true, k, parent
    }
    
    isExists, newK, newParent := findDepthAndParent(node.Left, val, k, node)
    
    if isExists {
        return isExists, newK, newParent
    }
    
    return findDepthAndParent(node.Right, val, k, node)
}