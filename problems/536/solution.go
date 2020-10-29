package main
import "unicode"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func str2tree(s string) *TreeNode {
    if len(s) == 0 {
        return nil
    }
    
    pos := 0
    
    return build("(" + s + ")", &pos)
}

func build(s string, i *int) *TreeNode {
    if *i == len(s) || s[*i] != '(' {
        return nil
    }
    
    neg, node := 1, &TreeNode{}
    *i++
    
    if s[*i] == '-' {
        neg *= -1
        *i++
    }
    
    for unicode.IsDigit(rune(s[*i])) {
        node.Val = node.Val * 10 + int(rune(s[*i]) - '0')
        *i++
    }
    
    node.Val *= neg
    node.Left = build(s, i)
    node.Right = build(s, i)
    *i++
    
    return node
}