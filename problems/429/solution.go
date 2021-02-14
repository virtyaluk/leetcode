package main
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func levelOrder(root *Node) [][]int {
    if root == nil {
        return [][]int{}
    }
    
    ans, q := [][]int{}, []*Node{root}
    
    for len(q) > 0 {
        curLevel, newQ := []int{}, []*Node{}
        
        for _, node := range q {
            curLevel = append(curLevel, node.Val)
            
            newQ = append(newQ, node.Children...)
        }
        
        ans = append(ans, curLevel)
        q = newQ
    }
    
    return ans
}