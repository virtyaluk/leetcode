package main
func maximumGap(nums []int) int {
    if len(nums) <= 1 {
        return 0
    }
    
    ans := 0
    nums = radixSort(nums)
    
    for i := 1; i < len(nums); i++ {
        if nums[i] - nums[i - 1] > ans {
            ans = nums[i] - nums[i - 1]
        }
    }
    
    return ans
}

func radixSort(nums []int) []int {
    for i := 0; i < 10; i++ {
        b := make([][]int, 10)
        
        for _, num := range nums {
            d := digit(num, i)
            
            b[d] = append(b[d], num)
        }
        
        nums = []int{}
        
        for _, bi := range b {
            nums = append(nums, bi...)
        }
    }
    
    return nums
}

func digit(a, b int) int {
    for b > 0 {
        b--
        a /= 10
    }

    return a % 10
}