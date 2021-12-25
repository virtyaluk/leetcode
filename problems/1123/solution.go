package main
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func lcaDeepestLeaves(root *TreeNode) *TreeNode {
    node, _ := find(root)
    
    return node
}

func find(node *TreeNode) (*TreeNode, int) {
    if node == nil {
        return node, 0
    }
    
    lnode, lh := find(node.Left)
    rnode, rh := find(node.Right)
    
    if lh == rh {
        return node, lh + 1
    } else if lh > rh {
        return lnode, lh + 1
    }
    
    return rnode, rh + 1
}