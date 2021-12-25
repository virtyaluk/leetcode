package main
func tupleSameProduct(nums []int) int {
    ans, m, n := 0, map[int]int{}, len(nums)
    
    for i := 0; i < n - 1; i++ {
        for j := i + 1; j < n; j++ {
            m[nums[i] * nums[j]]++
        }
    }
    
    for _, v := range m {
        ans += (v - 1) * v * 4
    }
    
    return ans
}