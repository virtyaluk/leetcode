package main
import lls "github.com/emirpasic/gods/stacks/linkedliststack"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type BSTIterator struct {
    st *lls.Stack
    root *TreeNode
}


func Constructor(root *TreeNode) BSTIterator {
    return BSTIterator{
        lls.New(),
        root,
    }
}


func (this *BSTIterator) Next() int {
    ans := 0
    
    for !this.st.Empty() || this.root != nil {
        if this.root != nil {
            this.st.Push(this.root)
            this.root = this.root.Left
        } else {
            res, _ := this.st.Pop()
            node := res.(*TreeNode)
            ans,this.root = node.Val, node.Right
            break
        }
    }
    
    return ans
}


func (this *BSTIterator) HasNext() bool {
    return !this.st.Empty() || this.root != nil
}


/**
 * Your BSTIterator object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */