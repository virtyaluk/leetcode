package main
func maxEnvelopes(envelopes [][]int) int {
    dp := []int{}
    
    sort.Slice(envelopes, func (i, j int) bool {
        if envelopes[i][0] == envelopes[j][0] {
            return envelopes[i][1] > envelopes[j][1]
        }
        
        return envelopes[i][0] < envelopes[j][0]
    })
    
    for _, e := range envelopes {
        idx := lowerBound(dp, e[1])
        
        if len(dp) == 0 || idx >= len(dp) {
            dp = append(dp, e[1])
        } else if dp[idx] > e[1] {
            dp[idx] = e[1]
        }
    }
    
    return len(dp)
}

func lowerBound(ar []int, num int) int {
    lo, hi := 0, len(ar) - 1
    
    for lo <= hi {
        mid := lo + (hi - lo) / 2
        
        if ar[mid] >= num {
            hi = mid - 1
        } else {
            lo = mid + 1
        }
    }
    
    return lo
}