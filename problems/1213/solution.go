package main
func arraysIntersection(arr1 []int, arr2 []int, arr3 []int) []int {
    m, ans := map[int]int{}, []int{}
    
    for _, num := range arr1 { m[num]++ }
    for _, num := range arr2 { m[num]++ }
    for _, num := range arr3 { m[num]++ }
    
    for num, freq := range m {
        if freq == 3 {
            ans = append(ans, num)
        }
    }
    
    sort.Ints(ans)
    
    return ans
}