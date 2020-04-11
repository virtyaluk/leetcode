package main
func solve(board [][]byte)  {
    m := len(board)
    
    if m == 0 {
        return
    }
    
    n := len(board[0])
    
    for i := 0; i < n; i++ {
        dfs(board, 0, i)
        dfs(board, m - 1, i)
    }
    
    for j := 0; j < m; j++ {
        dfs(board, j, 0)
        dfs(board, j, n - 1)
    }
    
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if board[i][j] == 'P' {
                board[i][j] = 'O'
            } else if board[i][j] == 'O' {
                board[i][j] = 'X'
            }
        }
    }
}

func dfs(grid [][]byte, x, y int) {
    if x >= 0 && x < len(grid) && y >= 0 && y < len(grid[0]) && grid[x][y] == 'O' {
        grid[x][y] = 'P'
        
        dfs(grid, x - 1, y)
        dfs(grid, x + 1, y)
        dfs(grid, x, y - 1)
        dfs(grid, x, y + 1)
    }
}