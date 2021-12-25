package main
func smallestDivisor(nums []int, threshold int) int {
    lo, hi := 1, nums[len(nums) - 1]
    
    for lo <= hi {
        mid := lo + (hi - lo) / 2
        sum := findSum(nums, mid)
        
        if sum > threshold {
            lo = mid + 1
        } else {
            hi = mid - 1
        }
    }
    
    return lo
}

func findSum(nums []int, x int) int {
    sum := 0
    
    for _, num := range nums {
        sum += num / x
        
        if num % x != 0 {
            sum += 1
        }
    }
    
    return sum
}