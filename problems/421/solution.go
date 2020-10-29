package main
func findMaximumXOR(nums []int) int {
    ans := 0
    
    for i := 0; i < len(nums); i++ {
        for j := i; j < len(nums); j++ {
            if nums[i] ^ nums[j] > ans {
                ans = nums[i] ^ nums[j]
            }
}

    }
    
    return ans
}