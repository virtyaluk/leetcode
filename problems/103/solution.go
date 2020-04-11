package main
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func zigzagLevelOrder(root *TreeNode) [][]int {
    if root == nil {
        return [][]int{}
    }
    
    ans, q, dir := [][]int{}, []*TreeNode{root}, true
    
    for len(q) > 0 {
        curLvl, newQ := []int{}, []*TreeNode{}
        
        for _, node := range q {
            curLvl = append(curLvl, node.Val)
            
            if node.Left != nil {
                newQ = append(newQ, node.Left)
            }
            
            if node.Right != nil {
                newQ = append(newQ, node.Right)
            }
        }
        
        if !dir {
            reverse(curLvl)
        }
        
        ans = append(ans, curLvl)
        q = newQ
        dir = !dir
    }
    
    return ans
}

func reverse(ar []int) {
    lo, hi := 0, len(ar) - 1
    
    for lo < hi {
        ar[lo], ar[hi] = ar[hi], ar[lo]
        lo++
        hi--
    }
}
