package main
func maximumProduct(nums []int) int {
    first, second, third, min1, min2, max1, max2 := -1001, -1001, -1001, 1001, 1001, 0, 0
    
    for _, v := range nums {
        if v < min1 {
            min2, min1 = min1, v
        } else if v < min2 {
            min2 = v
        }
        
        if v > first {
            third, second, first = second, first, v
        } else if v > second {
            third, second = second, v
        } else if v > third {
            third = v
        }
    }
    
    max1 = min1 * min2 * first
    max2 = first * second * third
    
    if max1 > max2 {
        return max1
    }
    
    return max2
}