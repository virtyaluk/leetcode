package main
func findKthPositive(arr []int, k int) int {
    ans, i := 0, 0
    
    for k > 0 {
        ans++
        
        if i < len(arr) && arr[i] == ans {
            i++
        } else {
            k--
        }
    }
    
    return ans
}