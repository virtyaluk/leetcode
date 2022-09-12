package main
func containsPattern(arr []int, m int, k int) bool {
    for i, count := m, 0; i < len(arr); i++ {
        if arr[i] != arr[i - m] {
            count = 0
        } else {
            count++
            
            if count == m * (k - 1) {
                return true
            }
        }
    }
    
    return false
}