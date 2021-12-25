package main
func uniqueOccurrences(arr []int) bool {
    m, count := map[int]int{}, map[int]struct{}{}
    
    for _, num := range arr {
        m[num]++
    }
    
    for _, v := range m {
        if _, ok := count[v]; ok {
            return false
        }
        
        count[v] = struct{}{}
    }
    
    return true
}