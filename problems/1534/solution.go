package main
func countGoodTriplets(arr []int, a int, b int, c int) int {
    ans, n := 0, len(arr)
    
    for i := 0; i < n - 2; i++ {
        for j := i + 1; j < n - 1; j++ {
            for k := j + 1; k < n; k++ {
                if abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c {
                    ans++
                }
            }
        }
    }
    
    return ans
}

func abs(a int) int {
    if a < 0 {
        return a * -1
    }
    
    return a
}