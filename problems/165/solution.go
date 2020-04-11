package main
func compareVersion(version1 string, version2 string) int {
    v1, v2 := strings.Split(version1, "."), strings.Split(version2, ".")
    
    for i := 0; i < max(len(v1), len(v2)); i++ {
        sv1, sv2 := 0, 0
        
        if i < len(v1) {
            sv1, _ = strconv.Atoi(v1[i])
        }
        
        if i < len(v2) {
            sv2, _ = strconv.Atoi(v2[i])
        }
        
        if sv1 > sv2 {
            return 1
        } else if sv1 < sv2 {
            return -1
        }
    }
    
    return 0
}

func max(a, b int) int {
    if a > b { return a }
    return b
}