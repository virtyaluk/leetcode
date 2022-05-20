package main
func destCity(paths [][]string) string {
    m := map[string]int{}
    
    for _, path := range paths {
        m[path[0]]--
        m[path[1]]++
    }
    
    for k, v := range m {
        if v >= 1 {
            return k
        }
    }
    
    return ""
}