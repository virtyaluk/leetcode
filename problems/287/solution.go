package main
func findDuplicate(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    
    slow, fast := nums[0], nums[0]
    
    for true {
        slow, fast = nums[slow], nums[nums[fast]]
        
        if slow == fast {
            break
        }
    }
    
    slow = nums[0]
    
    for slow != fast {
        slow, fast = nums[slow], nums[fast]
    }
    
    return fast
}