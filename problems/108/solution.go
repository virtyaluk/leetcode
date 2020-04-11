package main
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sortedArrayToBST(nums []int) *TreeNode {
    return helper(nums, 0, len(nums))
}

func helper(nums []int, left, right int) *TreeNode {
    if left == right {
        return nil
    }
    
    mid := left + (right - left) / 2
    return &TreeNode{nums[mid], helper(nums, left, mid), helper(nums, mid + 1, right)}
}