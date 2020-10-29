package main
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func deleteNode(root *TreeNode, key int) *TreeNode {
    if root == nil {
        return root
    }
    
    if key > root.Val {
        root.Right = deleteNode(root.Right, key)
    } else if key < root.Val {
        root.Left = deleteNode(root.Left, key)
    } else if key == root.Val {
        if root.Left == nil && root.Right == nil {
            root = nil
        } else if root.Right != nil {
            root.Val = successor(root)
            root.Right = deleteNode(root.Right, root.Val)
        } else if root.Left != nil {
            root.Val = predecessor(root)
            root.Left = deleteNode(root.Left, root.Val)
        }
    }
    
    return root
}

func successor(node *TreeNode) int {
    node = node.Right
    
    for node.Left != nil {
        node = node.Left
    }
    
    return node.Val
}

func predecessor(node *TreeNode) int {
    node = node.Left
    
    for node.Right != nil {
        node = node.Right
    }
    
    return node.Val
}