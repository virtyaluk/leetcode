package main
func generate(numRows int) [][]int {
    if numRows == 0 {
        return [][]int{}
    }
    
    if numRows == 1 {
        return [][]int{[]int{1}}
    }
    
    ans := make([][]int, numRows)
    
    ans[0] = []int{1}
    ans[1] = []int{1,1}
    
    for i := 2; i < numRows; i++ {
        ans[i] = make([]int, i + 1)
        ans[i][0] = 1
        ans[i][i] = 1
        
        for j := 1; j < len(ans[i]) - 1; j++ {
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j]
        }
    }
    
    return ans
}