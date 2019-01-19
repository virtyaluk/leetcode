func twoSum(nums []int, target int) []int {
    m := make(map[int]int)
    
    for i := range nums {
        compl := target - nums[i]
        
        if val, ok := m[compl]; ok {
            return []int{val, i}
        }
        
        m[nums[i]] = i
    }
    
    return []int{0}
}