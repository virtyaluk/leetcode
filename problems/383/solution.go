package main
func canConstruct(ransomNote string, magazine string) bool {
    m :=map[int]int{}
    
    for _, v := range magazine {
        m[int(v)]++
    }
    
    for _, v := range ransomNote {
        v1, ok := m[int(v)]
        
        if ok && v1 > 0 {
            m[int(v)]--
        } else {
            return false
        }
    }
    
    return true
}