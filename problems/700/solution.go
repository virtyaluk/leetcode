package main
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func searchBST(root *TreeNode, val int) *TreeNode {
    cur := root
    
    for cur != nil {
        if cur.Val == val {
            return cur
        } else if val < cur.Val {
            cur = cur.Left
        } else {
            cur = cur.Right
        }
    }
    
    return nil
}
