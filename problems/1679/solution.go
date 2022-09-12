package main
func maxOperations(nums []int, k int) int {
    ans, m := 0, map[int]int{}
    
    for _, num := range nums {
        if _, ok := m[num]; ok && m[num] > 0 {
            m[num]--
            ans++
        } else {
            m[k - num]++
        }
    }
    
    return ans
}