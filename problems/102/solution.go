package main
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
    if root == nil {
        return [][]int{}
    }
    
    ans, q := [][]int{}, []*TreeNode{root}
    
    for len(q) > 0 {
        curLevel, newQ := []int{}, []*TreeNode{}
        
        for _, node := range q {
            curLevel = append(curLevel, node.Val)
            
            if node.Left != nil {
                newQ = append(newQ, node.Left)
            }
            
            if node.Right != nil {
                newQ = append(newQ, node.Right)
            }
        }
        
        ans = append(ans, curLevel)
        q = newQ
    }
    
    return ans
}