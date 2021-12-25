package main
func numSubmatrixSumTarget(matrix [][]int, target int) int {
    ans, m, n := 0, len(matrix), len(matrix[0])
    ps := make([][]int, m + 1)
    ps[0] = make([]int, n + 1)
    
    for i := 1; i <= m; i++ {
        ps[i] = make([]int, n + 1)
        
        for j := 1; j <= n; j++ {
            ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + matrix[i - 1][j - 1]
        }
    }
    
    for startRow := 1; startRow <= m; startRow++ {
        for endRow := startRow; endRow <= m; endRow++ {
            m := map[int]int{0: 1}
            
            for col := 1; col <= n; col++ {
                sum := ps[endRow][col] - ps[startRow - 1][col]
                
                ans += m[sum - target]
                m[sum]++
            }
        }
    }
    
    return ans
}