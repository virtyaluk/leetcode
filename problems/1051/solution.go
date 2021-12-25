package main
func heightChecker(heights []int) int {
    curHeight, ans, nh := 0, 0, make([]int, 101)
    
    for _, v := range heights {
        nh[v]++
    }
    
    for i := 0; i < len(heights); i++ {
        for nh[curHeight] == 0 {
            curHeight++
        }
        
        if heights[i] != curHeight {
            ans++
        }
        
        nh[curHeight]--
    }
    
    return ans
}