package main
func leastInterval(tasks []byte, n int) int {
    abc := make([]int, 26)
    
    for _, ch := range tasks {
        abc[ch - 'A']++
    }
    
    sort.Ints(abc)
    
    m := abc[25] - 1
    freq := m * n
    
    for i := 24; i >= 0; i-- {
        if abc[i] == 0 {
            break
        }
        
        freq -= min(m, abc[i])
    }
    
    return len(tasks) + max(0, freq)
}

func min(a, b int) int {
    if a < b { return a }
    return b
}

func max(a, b int) int {
    if a > b { return a }
    return b
}