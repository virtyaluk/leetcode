package main
func islandPerimeter(grid [][]int) int {
    if len(grid) == 0 || len(grid[0]) == 0 {
        return 0
    }
    
    p := 0
    
    for i := 0; i < len(grid); i++ {
        for j := 0; j < len(grid[0]); j++ {
            if grid[i][j] == 0 {
                continue
            }
            
            if i == 0 || grid[i - 1][j] == 0 {
                p++
            }
            
            if j == 0 || grid[i][j - 1] == 0 {
                p++
            }
            
            if i == len(grid) - 1 || grid[i + 1][j] == 0 {
                p++
            }
            
            if j == len(grid[0]) - 1 || grid[i][j + 1] == 0 {
                p++
            }
        }
    }
    
    return p
}