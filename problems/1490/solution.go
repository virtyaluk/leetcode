package main
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func cloneTree(root *Node) *Node {
    if root == nil {
        return nil
    }
    
    node := &Node{root.Val, []*Node{}}
    
    for _, ch := range root.Children {
        node.Children = append(node.Children, cloneTree(ch))
    }
    
    return node
}