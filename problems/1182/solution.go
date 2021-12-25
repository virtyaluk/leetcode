package main
func shortestDistanceColor(colors []int, queries [][]int) []int {
    n, ans, dists := len(colors), make([]int, len(queries)), make([][]int, 3)
    
    for i := range dists {
        dists[i] = make([]int, n)
        
        for j := range dists[i] {
            dists[i][j] = -1
        }
    }
    
    for i := 0; i < n; i++ {
        for color := 1; color <= 3; color++ {
            if color == colors[i] {
                dists[color - 1][i] = 0;
            } else if i > 0 {
                if dists[color - 1][i - 1] != -1 {
                    dists[color - 1][i] = 1 + dists[color - 1][i - 1]
                }
            }
        }
    }
    
    for i := n - 1; i >= 0; i-- {
        for color := 1; color <= 3; color++ {
            if color == colors[i] {
                dists[color - 1][i] = 0
            } else if i + 1 < n {
                next := -1
                
                if dists[color - 1][i + 1] != -1 {
                    next = 1 + dists[color - 1][i + 1]
                }
                
                if next != -1 && dists[color - 1][i] != -1 {
                    dists[color - 1][i] = min(dists[color - 1][i], next)
                } else {
                    dists[color - 1][i] = max(dists[color - 1][i], next)
                }
            }
        }
    }
    
    for idx, query := range queries {
        i, c := query[0], query[1]
        
        ans[idx] = dists[c - 1][i]
    }
    
    return ans
}

func min(a, b int) int {
    if a < b {
        return a
    }
    
    return b
}

func max(a, b int) int {
    if a > b {
        return a
    }
    
    return b
}