package main
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Left *Node
 *     Right *Node
 * }
 */

func treeToDoublyList(root *Node) *Node {
    if root == nil {
        return nil
    }
    
    list := []*Node{}
    
    traverse(root, &list)
    
    for i := 1; i < len(list); i++ {
        list[i - 1].Right = list[i]
        list[i].Left = list[i - 1]
    }
    
    last := list[len(list) - 1]
    list[0].Left = last
    last.Right = list[0]
    
    return list[0]
}

func traverse(node *Node, list *[]*Node) {
    if node == nil {
        return
    }
    
    traverse(node.Left, list)
    
    *list = append(*list, node)
    
    traverse(node.Right, list)
}