package main
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Neighbors []*Node
 * }
 */
func cloneGraph(node *Node) *Node {
    return clone(node, make(map[*Node]*Node))
}

func clone(node *Node, m map[*Node]*Node) *Node {
    if node == nil {
        return nil
    }
    
    if found, ok := m[node]; ok {
        return found
    }
    
    cloned := &Node{node.Val, nil}
    m[node] = cloned
    
    for _, neighbor := range node.Neighbors {
        cloned.Neighbors = append(cloned.Neighbors, clone(neighbor, m))
    }
    
    return cloned
}