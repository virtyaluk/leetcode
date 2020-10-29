package main
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var mostFreq int
var freq map[int]int

func findFrequentTreeSum(root *TreeNode) []int {
    mostFreq, freq = 0, make(map[int]int)
    ans := []int{}
    
    traverse(root)
    
    for k, v := range freq {
        if v == mostFreq {
            ans = append(ans, k)
        }
    }
    
    return ans
}

func traverse(node *TreeNode) int {
    if node == nil {
        return 0
    }
    
    sum := node.Val + traverse(node.Left) + traverse(node.Right)
    freq[sum]++
    
    if freq[sum] > mostFreq {
        mostFreq = freq[sum]
    }
    
    return sum
}

