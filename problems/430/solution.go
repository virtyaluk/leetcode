package main
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Prev *Node
 *     Next *Node
 *     Child *Node
 * }
 */

func flatten(root *Node) *Node {
    tail := root
    
    for tail != nil {
        next := tail.Next
        
        if tail.Child != nil {
            tail.Next = flatten(tail.Child)
            tail.Next.Prev = tail
            tail.Child = nil
            
            for tail.Next != nil {
                tail = tail.Next
            }
        }
        
        tail.Next = next
        
        if tail.Next != nil {
            tail.Next.Prev = tail
        }
        
        tail = tail.Next
    }
    
    return root
}