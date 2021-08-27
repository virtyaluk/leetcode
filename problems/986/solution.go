package main
func intervalIntersection(A [][]int, B [][]int) [][]int {
    ans, ai, bi := [][]int{}, 0, 0
    
    for ai < len(A) && bi < len(B) {
        xs, xe := max(A[ai][0], B[bi][0]), min(A[ai][1], B[bi][1])
        
        if xs <= xe {
            ans = append(ans, []int{xs, xe})
        }
        
        if A[ai][1] < B[bi][1] {
            ai++
        } else {
            bi++
        }
    }
    
    return ans
}

func min(a, b int) int {
    if a < b { return a }
    return b
}

func max(a, b int) int {
    if a > b { return a }
    return b
}