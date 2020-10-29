package main
func findDuplicates(nums []int) []int {
    ans, m := []int{}, map[int]int{}
    
    for _, v := range nums {
        m[v]++
        
        if m[v] > 1 {
            ans = append(ans, v)
        }
    }
    
    return ans
}