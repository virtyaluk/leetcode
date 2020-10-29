package main
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func boundaryOfBinaryTree(root *TreeNode) []int {
    ans := []int{}
    
    if root == nil {
        return ans
    }
    
    ans = append(ans, root.Val)
    
    leftBoundaryTraverse(root.Left, &ans)
    leafBoundaryTraverse(root.Left, &ans)
    leafBoundaryTraverse(root.Right, &ans)
    rightBoundaryTraverse(root.Right, &ans)
    
    return ans
}

func leftBoundaryTraverse(root *TreeNode, ans *[]int) {
    if root == nil {
        return
    }
    
    if root.Left != nil {
        *ans = append(*ans, root.Val)
        leftBoundaryTraverse(root.Left, ans)
    } else if root.Right != nil {
        *ans = append(*ans, root.Val)
        leftBoundaryTraverse(root.Right, ans)
    }
}

func leafBoundaryTraverse(root *TreeNode, ans *[]int) {
    if root == nil {
        return
    }
    
    if root.Left == nil && root.Right == nil {
        *ans = append(*ans, root.Val)
    }
    
    leafBoundaryTraverse(root.Left, ans)
    leafBoundaryTraverse(root.Right, ans)
}

func rightBoundaryTraverse(root *TreeNode, ans *[]int) {
    if root == nil {
        return
    }
    
    if root.Right != nil {
        rightBoundaryTraverse(root.Right, ans)
        *ans = append(*ans, root.Val)
    } else if root.Left != nil {
        rightBoundaryTraverse(root.Left, ans)
        *ans = append(*ans, root.Val)
    }
}