package main
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func kthSmallest(root *TreeNode, k int) int {    
    if root == nil {
        return 0
    }
    
    curNode, count, kthSmall := root, 0, 0
    
    for curNode != nil {
        if curNode.Left == nil {
            count++
            
            if count == k {
                kthSmall = curNode.Val
            }
            
            curNode = curNode.Right
        } else {
            prev := curNode.Left
            
            for prev.Right != nil && prev.Right != curNode {
                prev = prev.Right
            }
            
            if prev.Right == nil {
                prev.Right = curNode
                curNode = curNode.Left
            } else {
                prev.Right = nil
                count++
                
                if count == k {
                    kthSmall = curNode.Val
                }
                
                curNode = curNode.Right
            }
        }
    }
    
    return kthSmall
}