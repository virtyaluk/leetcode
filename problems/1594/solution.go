package main
var ans int

func maxProductPath(grid [][]int) int {
    ans = -1
    m, n := len(grid), len(grid[0])
    
    bfs(grid, m, n, 0, 0, 1)
    
    if ans < 0 {
        return -1
    }
    
    return ans % 1000000007
}

func bfs(g [][]int, m, n, i, j, p int) {
    if i >= m || j >= n {
        return
    }
    
    if g[i][j] == 0 {
        if ans < 0 {
            ans = 0
        }
        
        return
    }
    
    p *= g[i][j]
    
    if i == m - 1 && j == n - 1 && p >= ans {
        ans = p
    }
    
    bfs(g, m, n, i + 1, j, p)
    bfs(g, m, n, i, j + 1, p)
}