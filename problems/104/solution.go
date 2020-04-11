package main
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxDepth(root *TreeNode) int {
    ans := 0
    
    helper(root, 0, &ans)
    
    return ans
}

func helper(node *TreeNode, depth int, ans *int) {
    if node == nil {
        return
    }
    
    depth++
    
    if depth > *ans {
        *ans = depth
    }
    
    helper(node.Left, depth, ans)
    helper(node.Right, depth, ans)
}