package main
func pancakeSort(A []int) []int {
    ans, sortVal := []int{}, len(A)
    
    for sortVal > 0 {
        idx := index(A, sortVal)
        
        if idx != sortVal - 1 {
            if idx != 0 {
                ans = append(ans, idx + 1)
                flip(A, idx + 1)
            }
            
            ans = append(ans, sortVal)
            flip(A, sortVal)
        }
        
        sortVal--
    }
    
    return ans
}

func index(ar []int, needle int) int {
    for i, val := range ar {
        if val == needle {
            return i
        }
    }
    
    return -1
}

func flip(ar []int, k int) {
    i := 0
    
    for i < k / 2 {
        ar[i], ar[k - i - 1] = ar[k - i - 1], ar[i]
        i++
    }
}