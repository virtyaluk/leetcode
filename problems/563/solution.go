package main
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findTilt(root *TreeNode) int {
    ans := 0
    
    traverse(root, &ans)
    
    return ans
}

func traverse(node *TreeNode, ans *int) int {
    if node == nil {
        return 0
    }
    
    left, right := traverse(node.Left, ans), traverse(node.Right, ans)
    
    *ans += abs(left - right)
    
    return left + right + node.Val
}

func abs(a int) int {
    if a < 0 { return a * -1 }
    return a
}