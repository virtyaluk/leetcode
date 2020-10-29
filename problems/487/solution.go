package main
func findMaxConsecutiveOnes(nums []int) int {
    // hold position of left pointer and last occurence of 0 (-1 for now)
    ans, left, zero := 0, 0, -1
    
    for right, num := range nums {
        if num == 1 {
            // if 1, check window size
            ans = max(ans, right - left + 1)
        } else {
            if zero != -1 {
                // update left bound with most recent zero, if we spotted one so far
                left = zero + 1
            }

            // check window size again
            ans = max(ans, right - left + 1)
            
            // update last occurence of zero to be current right bound of the window
            zero = right
        }
    }
    
    return ans
}

func max(a, b int) int {
    if a > b { return a }
    return b
}