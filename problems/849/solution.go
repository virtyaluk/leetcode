package main
func maxDistToClosest(seats []int) int {
    ans := 0
    
    for seats[ans] != 1 {
        ans++
    }
    
    for i := ans; i < len(seats); i++ {
        if seats[i] == 0 {
            continue
        }
        
        j := i
        
        for i + 1 < len(seats) && seats[i + 1] != 1 {
            i++
        }
        
        if i == len(seats) - 1 {
            ans = max(ans, i - j)
        } else {
            ans = max(ans, (i - j + 1) / 2)
        }
    }
    
    return ans
}

func max(a, b int) int {
    if a > b {
        return a
    }
    
    return b
}