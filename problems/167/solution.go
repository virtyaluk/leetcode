package main
func twoSum(numbers []int, target int) []int {
    i, j := 0, len(numbers) - 1
    sum := numbers[i] + numbers[j]
    
    for sum != target {
        if sum < target {
            i++
        } else {
            j--
        }
        
        sum = numbers[i] + numbers[j]
    }
    
    return []int {i + 1, j + 1}
}