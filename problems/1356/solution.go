package main
func sortByBits(arr []int) []int {
    sort.Slice(arr, func (i, j int) bool {
        ic, jc := popcount(arr[i]), popcount(arr[j])
        
        if ic == jc {
            return arr[i] < arr[j]
        }
        
        return ic < jc
    })
    
    return arr
}

func popcount(n int) int {
    count := 0
    
    for n > 0 {
        n = n & (n - 1)
        count++
    }
    
    return count
}