package main
func sortColors(nums []int)  {
    p0, p2, cur := 0, len(nums) - 1, 0
    
    for cur <= p2 {
        if nums[cur] == 0 {
            nums[cur], nums[p0] = nums[p0], nums[cur]
            cur++
            p0++
        } else if nums[cur] == 2 {
            nums[cur], nums[p2] = nums[p2], nums[cur]
            p2--
        } else {
            cur++
        }
    }
}