package main
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sumRootToLeaf(root *TreeNode) int {
    if root == nil {
        return 0
    }
    
    ans, curPath := 0, 0
    
    for root != nil {
        if root.Left != nil {
            prev, steps := root.Left, 1
            
            for prev.Right != nil && prev.Right != root {
                prev = prev.Right
                steps++
            }
            
            if prev.Right == nil {
                curPath = (curPath << 1) | root.Val
                prev.Right = root
                root = root.Left
            } else {
                if (prev.Left == nil) {
                    ans += curPath
                }
                
                curPath >>= steps
                prev.Right = nil
                root = root.Right
            }
        } else {
            curPath = (curPath << 1) | root.Val
            
            if root.Right == nil {
                ans += curPath
            }
            
            root = root.Right
        }
    }
    
    return ans
}