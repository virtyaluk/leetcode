package main
func replaceElements(arr []int) []int {
    cm := -1
    
    for i := len(arr) - 1; i >= 0; i-- {
        temp := arr[i]
        
        arr[i] = cm
        
        cm = max(cm, temp)
    }
    
    return arr
}

func max(a, b int) int {
    if a > b {
        return a
    }
    
    return b
}