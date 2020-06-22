package main
func intersect(nums1 []int, nums2 []int) []int {
    m, ans := map[int]int{}, []int{}
    
    for _, num := range nums1 {
        m[num]++
    }
    
    for _, num := range nums2 {
        if m[num] > 0 {
            m[num]--
            ans = append(ans, num)
        }
    }
    
    return ans
}