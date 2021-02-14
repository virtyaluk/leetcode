package main
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func averageOfLevels(root *TreeNode) []float64 {
    if root == nil {
        return []float64{}
    }
    
    ans, q := []float64{}, []*TreeNode{root}
    
    for len(q) > 0 {
        newQ, curAvg, n := []*TreeNode{}, 0.0, float64(len(q))
        
        for _, node := range q {
            curAvg += float64(node.Val)
            
            if node.Left != nil {
                newQ = append(newQ, node.Left)
            }
            
            if node.Right != nil {
                newQ = append(newQ, node.Right)
            }
        }
        
        ans = append(ans, curAvg / n)
        q = newQ
    }
    
    return ans
}