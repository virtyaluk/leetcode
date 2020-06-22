package main
var dir = [][]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}

func longestIncreasingPath(matrix [][]int) int {
    ans, m, n := 0, len(matrix), len(matrix[0])
    memo := make([][]int, m)
    
    for i := 0; i < m; i++ {
        memo[i] = make([]int, n)
    }
    
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            ans = max(ans, dfs(matrix, memo, i, j))
        }
    }
    
    return ans
}

func dfs(matrix, memo [][]int, i, j int) int {
    if memo[i][j] != 0 {
        return memo[i][j]
    }
    
    m, n := len(matrix), len(matrix[0])
    
    for _, d := range dir {
        x, y := i + d[0], j + d[1]
        
        if x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j] {
            memo[i][j] = max(memo[i][j], dfs(matrix, memo, x, y))
        }
    }
    
    memo[i][j]++
    
    return memo[i][j]
}

func max(a, b int) int {
    if a > b {
        return a
    }
    
    return b
}