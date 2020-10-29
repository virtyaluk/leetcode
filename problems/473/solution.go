package main
func makesquare(matchsticks []int) bool {
    n, sum := len(matchsticks), 0
    
    for _, match := range matchsticks {
        sum += match
    }
    
    if sum % 4 != 0 {
        return false
    }
    
    all, sideSum, usedMasks, halfMasks := (1 << n) - 1, sum / 4, []int{}, make([]bool, 1 << n)
    
    for mask := 0; mask <= all; mask++ {
        subsetSum := 0
        
        for i, match := range matchsticks {
            if (mask & (1 << i)) != 0 {
                subsetSum += match
            }
        }
        
        if subsetSum == sideSum {
            for _, prevMask := range usedMasks {
                if mask & prevMask == 0 {
                    halfMask := mask | prevMask
                    halfMasks[halfMask] = true
                    
                    if halfMasks[all ^ halfMask] {
                        return true
                    }
                }
            }
            
            usedMasks = append(usedMasks, mask)
        }
    }
    
    return false
}