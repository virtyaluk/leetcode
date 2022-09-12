package main
func sumOddLengthSubarrays(arr []int) int {
    ans := 0
    
    for left, right := 1, len(arr); left - 1 < len(arr); left, right = left + 1, right - 1 {
        ans += (left * right + 1) / 2 * arr[left - 1]
    }
    
    return ans
}