package main
func wiggleMaxLength(nums []int) int {
    start1, start2, count1, count2 := true, false, 1, 1
    
    for i := 1; i < len(nums); i++ {
        if nums[i] == nums[i - 1] {
            continue
        }
        
        val := nums[i - 1] - nums[i] > 0
        
        if start1 == !val {
            start1 = val
            count1++
        }
        
        if start2 == !val {
            start2 = val
            count2++
        }
    }
    
    if count1 > count2 {
        return count1
    }
    
    return count2
}