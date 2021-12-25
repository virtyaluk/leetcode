package main
func oddCells(n int, m int, indices [][]int) int {
    grid, ans := make([][]int, n), 0
    
    for i, _ := range grid {
        grid[i] = make([]int, m)
    }
    
    for _, ind := range indices {
        ri, ci := ind[0], ind[1]
        
        for i := 0; i < m; i++ {
            grid[ri][i]++
        }
        
        for i := 0; i < n; i++ {
            grid[i][ci]++
        }
    }
    
    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            if grid[i][j] % 2 != 0 {
                ans++
            }
        }
    }
    
    return ans
}