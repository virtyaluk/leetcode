package main
func fizzBuzz(n int) []string {
    ans := make([]string, n)
    
    for i := 0; i < n; i++ {
        num := ""
        
        if (i + 1) % 3 == 0 {
            num += "Fizz"
        }
        
        if (i + 1) % 5 == 0 {
            num += "Buzz"
        }
        
        if len(num) == 0 {
            num = strconv.Itoa(i + 1)
        }
        
        ans[i] = num
    }
    
    return ans
}