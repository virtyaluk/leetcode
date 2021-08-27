package main
import "sort"

func numMagicSquaresInside(grid [][]int) int {
    count := 0
    
    for i := 0; i < len(grid) - 2; i++ {
        for j := 0; j < len(grid[0]) - 2; j++ {
            if grid[i + 1][j + 1] != 5 {
                continue
            }
            
            if check(grid[i][j], grid[i + 1][j], grid[i + 2][j],
                     grid[i][j + 1], grid[i + 1][j + 1], grid[i + 2][j + 1],
                     grid[i][j + 2], grid[i + 1][j + 2], grid[i + 2][j + 2]) {
                count++
            }
        }
    }
    
    return count
}

func check(a, b, c, d, e, f, g, h, i int) bool {
    nums := []int{a, b, c, d, e, f, g, h, i}
    
    sort.Ints(nums)
    
    for i, v := range nums {
        if i + 1 != v {
            return false
        }
    }
    
    return a + b + c == 15 &&  d + e + f == 15 && g + h + i == 15 && a + d + g == 15 && b + e + h == 15 && c + f + i == 15 && a + e + i == 15 && c + e + g == 15
}