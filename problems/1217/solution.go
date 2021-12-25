package main
func minCostToMoveChips(position []int) int {
    odd, even := 0, 0
    
    for _, pos := range position {
        if pos % 2 == 0 {
            even++
        } else {
            odd++
        }
    }
    
    if even < odd {
        return even
    }
    
    return odd
}