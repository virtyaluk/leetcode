package main
func firstUniqChar(s string) int {
    m := make(map[int]int)
    
    for _, v := range s {
        m[int(v)]++
    }
    
    for i, v := range s {
        if m[int(v)] == 1 {
            return i
        }
    }
    
    return -1
}