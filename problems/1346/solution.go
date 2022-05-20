package main
func checkIfExist(arr []int) bool {
    for i, n := range arr {
        for j, m := range arr {
            if i == j {
                continue
            }
            
            if n*2 == m || n == m*2 {
                return true
            }
            
            // if (n % 2 == 0 && n/2 == m) || (m % 2 == 0 && m/2 == n) {
            //     return true
            // }
        }
    }
    
    return false
}