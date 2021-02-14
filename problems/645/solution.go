package main
func findErrorNums(nums []int) []int {
    dif, a, b := 0, 0, 0
    
    for _, num := range nums {
        dif ^= num
    }
    
    for i := 1; i <= len(nums); i++ {
        dif ^= i
    }
    
    dif = dif & -dif
    
    for _, num := range nums {
        if (dif & num) != 0 {
            a ^= num
        } else {
            b ^= num
        }
    }
    
    for i := 1; i <= len(nums); i++ {
        if (dif & i) != 0 {
            a ^= i
        } else {
            b ^= i
        }
    }
    
    for _, num := range nums {
        if num == b {
            return []int{b, a}
        }
    }
    
    return []int{a, b}
}