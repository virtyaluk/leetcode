package main
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func widthOfBinaryTree(root *TreeNode) int {
    if root == nil {
        return 0
    }
    
    q, m := []*Pair{&Pair{root, 1}}, 0
    
    for len(q) > 0 {
        lov, hiv := q[0].Val, q[len(q) - 1].Val
        m = max(m, hiv - lov + 1)
        nq := []*Pair{}
        
        for _, p := range q {
            if p.Node.Left != nil {
                nq = append(nq, &Pair{p.Node.Left, p.Val * 2 - 1})
            }
            
            if p.Node.Right != nil {
                nq = append(nq, &Pair{p.Node.Right, p.Val * 2})
            }
        }
        
        q = nq
    }
    
    return m
}

func max(a, b int) int {
    if a > b {
        return a
    }
    
    return b
}

type Pair struct {
    Node *TreeNode
    Val int
}