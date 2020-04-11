package main
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func recoverTree(root *TreeNode)  {
    var traverse func(*TreeNode)
    var first, last, prev *TreeNode
    
    traverse = func (node *TreeNode) {
        if node == nil {
            return
        }
        
        traverse(node.Left)
        
        if prev != nil && prev.Val > node.Val {
            if first == nil {
                first = prev
            }
            
            last = node
        }
        
        prev = node
        
        traverse(node.Right)
    }
    
    traverse(root)
    
    first.Val, last.Val = last.Val, first.Val
}