package main
const MaxInt = int(^uint(0) >> 1)
const MinInt = -MaxInt - 1

func thirdMax(nums []int) int {
    first, second, third := MinInt, MinInt, MinInt
    
    for _, n := range nums {
        if n > first {
            third, second, first = second, first, n
        } else if n < first && n > second {
            third, second = second, n
        } else if n < second && n > third {
            third = n
        }
    }
    
    if third == MinInt {
        return first
    }
    
    return third
}