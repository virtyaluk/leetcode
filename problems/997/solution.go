package main
func findJudge(N int, trust [][]int) int {
    people := make([]int, N)
    
    
    for _, ab := range trust {
        a, b := ab[0], ab[1]
        
        people[a - 1]--
        people[b - 1]++
    }
    
    for i := range people {
        if people[i] == N - 1 {
            return i + 1
        }
    }
    
    return -1
}