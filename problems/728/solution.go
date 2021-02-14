package main
func selfDividingNumbers(left int, right int) []int {
    numbers := []int{}
    
    for i := left; i <= right; i++ {
        digit := i
        isDivisible := true
	
        for digit > 0 {
            tens := digit % 10

            if tens == 0 || i % tens != 0 {
                isDivisible = false
                break
            }

            digit = int(digit/10)
        }
                
        if isDivisible {
            numbers = append(numbers, i)
        }  
    }
    
    return numbers
}