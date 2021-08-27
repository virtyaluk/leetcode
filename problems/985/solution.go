package main
func sumEvenAfterQueries(A []int, queries [][]int) []int {
    ans := make([]int, len(A))
            
    for i, query := range queries {
        A[query[1]] += query[0]
        sum := 0
        
        for _, v := range A {
            if v % 2 == 0 {
                sum += v
            }
        }
        
        ans[i] = sum
    }
    
    return ans
}