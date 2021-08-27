package main
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type Camera int

const (
    HasCam Camera = iota
    Covered
    NotCovered
)

func minCameraCover(root *TreeNode) int {
    ans := 0
    
    if helper(root, &ans) == NotCovered {
        return ans + 1
    }
    
    return ans
}

func helper(root *TreeNode, ans *int) Camera {
    if root == nil {
        return Covered
    }
    
    l, r := helper(root.Left, ans), helper(root.Right, ans)
    
    if l == NotCovered || r == NotCovered {
        (*ans)++
        return HasCam
    }
    
    if l == HasCam || r == HasCam {
        return Covered
    }
    
    return NotCovered
}