package main
var dirs = [][]int{[]int{1, 0}, []int{-1, 0}, []int{0, 1}, []int{0, -1}}

func exist(board [][]byte, word string) bool {
    m, n := len(board), len(board[0])
    visited := make([][]bool, m)
    
    for i, _ := range visited {
        visited[i] = make([]bool, n)
    }
    
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if board[i][j] == word[0] && dfs(board, visited, i, j, m, n, 0, word) {
                return true
            }
        }
    }
    
    return false
}

func dfs(g [][]byte, visited [][]bool, i, j, m, n, p int, word string) bool {
    if visited[i][j] {
        return false
    }
    
    p++
    visited[i][j] = true
    
    if p == len(word) {
        return true
    }
    
    for _, dir := range dirs {
        x, y := i + dir[0], j + dir[1]
        
        if checkBounds(x, y, m, n) && g[x][y] == word[p] && dfs(g, visited, x, y, m, n, p, word) {
            return true
        }
    }
    
    visited[i][j] = false
    
    return false
}

func checkBounds(x, y, m, n int) bool {
    return x >= 0 && x < m && y >= 0 && y < n
}