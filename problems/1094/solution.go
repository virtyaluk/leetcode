package main
func carPooling(trips [][]int, capacity int) bool {
    maxTrip := 0
    
    for _, trip := range trips {
        if trip[2] > maxTrip {
            maxTrip = trip[2]
        }
    }
    
    sum := make([]int, maxTrip + 1)
    
    for _, trip := range trips {
        sum[trip[1]] += trip[0]
        sum[trip[2]] -= trip[0]
    }
    
    curCap := 0
    
    for _, cpct := range sum {
        curCap += cpct
        
        if curCap > capacity {
            return false
        }
    }
    
    return true
}