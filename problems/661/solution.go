package main
func imageSmoother(M [][]int) [][]int {
    ans, rows := [][]int{}, len(M)
    
    for i, _ := range M {
        colls := len(M[i])
        newColls := make([]int, colls)
        ans = append(ans, []int{})
        
        for j, _ := range M[i] {
            top, bottom, left, right, sum, count := i - 1, i + 1, j - 1, j + 1, M[i][j], 1
            
            if top >= 0 {
                count++
                sum += M[top][j]
            }
            
            if bottom < rows {
                count++
                sum += M[bottom][j]
            }
            
            if left >= 0 {
                count++
                sum += M[i][left]
            }
            
            if right < colls {
                count++
                sum += M[i][right]
            }
            
            if left >= 0 && top >= 0 {
                count++
                sum += M[top][left]
            }
            
            if left >= 0 && bottom < rows {
                count++
                sum += M[bottom][left]
            }
            
            if right < colls && top >= 0 {
                count++
                sum += M[top][right]
            }
            
            if right < colls && bottom < rows {
                count++
                sum += M[bottom][right]
            }
            
            newColls[j] = sum / count
        }
        
        ans[i] = newColls
    }
    
    return ans
}