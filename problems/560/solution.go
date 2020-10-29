package main
func subarraySum(nums []int, k int) int {
    ans, sum, m := 0, 0, map[int]int{0:1}
    
    for _, num := range nums {
        sum += num
        
        ans += m[sum - k]
        m[sum]++
    }
    
    return ans
}