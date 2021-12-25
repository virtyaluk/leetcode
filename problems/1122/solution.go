package main
func relativeSortArray(arr1 []int, arr2 []int) []int {
    m := map[int]int{}
    
    for i, num := range arr2 {
        m[num] = i
    }
    
    sort.Slice(arr1, func(i, j int) bool {
        idx1, ok1 := m[arr1[i]]
        idx2, ok2 := m[arr1[j]]
        
        if ok1 && ok2 {
            return idx1 < idx2
        }
        
        if !ok1 && !ok2 {
            return arr1[i] < arr1[j]
        }
        
        if ok1 && !ok2 {
            return true
        }
        
        return false
    })
    
    return arr1
}