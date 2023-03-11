package main
const MOD int = 1000000007

func minAbsoluteSumDiff(nums1 []int, nums2 []int) int {
    ans, dif, sorted := 0, 0, []int{}
    
    for _, num := range nums1 {
        idx := sort.SearchInts(sorted, num)
        
        if len(sorted) > 0 && idx < len(sorted) && sorted[idx] == num {
            continue
        }
        
        sorted = append(sorted, num)
    }
    
    sort.Ints(sorted)
    
    for i := 0; i < len(nums1); i++ {
        cur := abs(nums1[i] - nums2[i])
        ans += cur
        
        if dif < cur {
            idx := sort.SearchInts(sorted, nums2[i])
            
            if idx < len(sorted) {
                dif = max(dif, cur - abs(sorted[idx] - nums2[i]))
            }
            
            if idx > 0 {
                dif = max(dif, cur - abs(sorted[idx - 1] - nums2[i]))
            }
        }
    }
    
    return (ans - dif) % MOD
}

func abs(a int) int {
    if a < 0 {
        return -a
    }
    
    return a
}

func max(a, b int) int {
    if a > b {
        return a
    }
    
    return b
}