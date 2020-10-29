package main
func hasPath(maze [][]int, start []int, destination []int) bool {
    visited := make([][]bool, len(maze))
    
    for i := range visited {
        visited[i] = make([]bool, len(maze[0]))
    }
    
    return dfs(maze, start, destination, visited)
}

// 0 - top, 1 - right, 2 - down, 3 - left

func dfs(grid [][]int, start, dest []int, visited [][]bool) bool {
    if visited[start[0]][start[1]] {
        return false
    }
    
    if start[0] == dest[0] && start[1] == dest[1] {
        return true
    }
    
    visited[start[0]][start[1]] = true
    
    up, right, down, left := start[0] - 1, start[1] + 1, start[0] + 1, start[1] - 1
    
    // up
    for up >= 0 && grid[up][start[1]] == 0 { up-- }
    
    if dfs(grid, []int{up + 1, start[1]}, dest, visited) { return true }
    
    // right
    for right < len(grid[0]) && grid[start[0]][right] == 0 { right++ }
    
    if dfs(grid, []int{start[0], right - 1}, dest, visited) { return true }
    
    // down
    for down < len(grid) && grid[down][start[1]] == 0 { down++ }
    
    if dfs(grid, []int{down - 1, start[1]}, dest, visited) { return true }
    
    // left
    for left >= 0 && grid[start[0]][left] == 0 { left-- }
    
    if dfs(grid, []int{start[0], left + 1}, dest, visited) { return true }
    
    return false
}