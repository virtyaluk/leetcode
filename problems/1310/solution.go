package main
func xorQueries(arr []int, queries [][]int) []int {
    ans := make([]int, len(queries))
    
    for i, query := range queries {
        for j := query[0]; j <= query[1]; j++ {
            ans[i] ^= arr[j]
        }
    }
    
    return ans
}