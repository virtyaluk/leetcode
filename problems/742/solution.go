package main
const MaxUint = ^uint(0) 
const MinUint = 0 
const MaxInt = int(MaxUint >> 1) 
const MinInt = -MaxInt - 1

type Res struct {
    leaf *TreeNode
    distToLeaf, distToTarget int
    foundTarget bool
}

var shorthestPath int
var shorthestLeaf *TreeNode

func findClosestLeaf(root *TreeNode, k int) int {
    shorthestPath, shorthestLeaf = MaxInt, nil
    
    dfs(root, k)
    
    return shorthestLeaf.Val
}

func dfs(root *TreeNode, k int) Res {
    res := Res{nil, MaxInt, MaxInt, false}
    
    if root == nil {
        return res
    }
    
    left, right := dfs(root.Left, k), dfs(root.Right, k)
    
    if left.leaf == nil && right.leaf == nil {
        res.leaf = root
        res.distToLeaf = 0
    } else {
        if left.distToLeaf <= right.distToLeaf {
            res.distToLeaf = 1 + left.distToLeaf
            res.leaf = left.leaf
        } else {
            res.distToLeaf = 1 + right.distToLeaf
            res.leaf = right.leaf
        }
    }
    
    if root.Val == k {
        res.foundTarget = true
        res.distToTarget = 0
        
        shorthestPath = res.distToLeaf
        shorthestLeaf = res.leaf
    } else if left.foundTarget || right.foundTarget {
        res.foundTarget = true
        
        if left.foundTarget {
            res.distToTarget = 1 + left.distToTarget
        } else {
            res.distToTarget = 1 + right.distToTarget
        }
        
        if res.distToTarget + res.distToLeaf < shorthestPath {
            shorthestPath = res.distToTarget + res.distToLeaf
            shorthestLeaf = res.leaf
        }
    }
    
    return res
}