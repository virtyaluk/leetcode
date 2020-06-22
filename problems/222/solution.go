package main
import "math"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func countNodes(root *TreeNode) int {
    if root == nil {
        return 0
    }
    
    cur, hLeft, hRight := root, 1, 1
    
    for cur.Left != nil {
        hLeft++
        cur = cur.Left
    }
    
    cur = root
    
    for cur.Right != nil {
        hRight++
        cur = cur.Right
    }
    
    if hLeft == hRight {
        return int(math.Pow(2.0, float64(hLeft))) - 1
    }
    
    return 1 + countNodes(root.Left) + countNodes(root.Right)
}