package main
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sumEvenGrandparent(root *TreeNode) int {
    if root == nil {
        return 0
    }
    
    ans := 0
    
    traverse(root, nil, nil, &ans)
    
    return ans
}

func traverse(node, parent, grandparent *TreeNode, ans *int) {
    if grandparent != nil && grandparent.Val % 2 == 0 {
        *ans += node.Val
    }
    
    if node.Left != nil {
        traverse(node.Left, node, parent, ans)
    }
    
    if node.Right != nil {
        traverse(node.Right, node, parent, ans)
    }
}