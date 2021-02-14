package main
func canPartitionKSubsets(nums []int, k int) bool {
    sum, max := 0, 0
    
    for _, num := range nums {
        sum += num
        
        if num > max {
            max = num
        }
    }
    
    if sum % k != 0 || max > sum / k {
        return false
    }
    
    sum /= k
    
    return backtrack(nums, k, sum, 0, 0)
}

func backtrack(nums []int, k, sum, curSum, i int) bool {
    if k == 1 {
        return true
    }
    
    if sum == curSum {
        return backtrack(nums, k - 1, sum, 0, 0)
    }
    
    for j := i; j < len(nums); j++ {
        if nums[j] > 0 && curSum + nums[j] <= sum {
            nums[j] *= -1
            
            if (backtrack(nums, k, sum, curSum + nums[j] * -1, j + 1)) {
                return true
            }
            
            nums[j] *= -1
        }
    }
    
    return false
}