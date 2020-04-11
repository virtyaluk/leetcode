package main
func subsets(nums []int) [][]int {
    ans := [][]int{}
    
    for i := 0; i < 1 << len(nums); i++ {
        sub := []int{}
        
        for j := 0; j < len(nums); j++ {
            if (i & (1 << j)) != 0 {
                sub = append(sub, nums[j])
            }
        }
        
        ans = append(ans, sub)
    }
    
    return ans
}