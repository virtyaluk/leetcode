package main


func canMakeArithmeticProgression(arr []int) bool {
    sort.Ints(arr)
    
    diff := abs(arr[1] - arr[0])
    
    for i := 0; i < len(arr) - 1; i++ {
        if abs(arr[i + 1] - arr[i]) != diff {
            return false
        }
    }
    
    return true
}

func abs(a int) int {
    if a < 0 {
        return a * -1
    }
    
    return a
}