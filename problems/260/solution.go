package main
func singleNumber(nums []int) []int {
    mask, dif, a, b := 0, 1, 0, 0
    
    for _, num := range nums {
        mask ^= num
    }
    
    for mask & dif == 0 {
        dif <<= 1
    }
    
    for _, num := range nums {
        if dif & num == 0 {
            a ^= num
        } else {
            b ^= num
        }
    }
    
    return []int{a, b}
}