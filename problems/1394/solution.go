package main
func findLucky(arr []int) int {
    hm, ans := map[int]int{}, -1
    
    for _, v := range arr {
        hm[v]++
    }
    
    for k, v := range hm {
        if k == v && k > ans {
            ans = k
        }
    }
    
    return ans
}