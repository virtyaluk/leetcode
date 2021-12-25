package main
func sumOfDigits(A []int) int {
    min := A[0]
    
    for _, num := range A {
        if num < min {
            min = num
        }
    }
    
    fmt.Println(min)
    
    min = (min % 10) + (min / 10)
    
    // if min % 9 == 0 {
    //     min = 9
    // } else {
    //     min %= 9
    // }
    
    if min % 2 == 0 {
        return 1
    }
    
    return 0
}