package main
func sortTransformedArray(nums []int, a int, b int, c int) []int {
    ans, lo, hi, ilo, ihi := make([]int, len(nums)), 0, len(nums) - 1, 0, len(nums) - 1
    
    for lo <= hi {
        lofn, hifn := fn(a, b, c, nums[lo]), fn(a, b, c, nums[hi])
        
        if a >= 0 {
            if lofn > hifn {
                ans[ihi] = lofn
                ihi--
                lo++
            } else {
                ans[ihi] = hifn
                ihi--
                hi--
            }
        } else {
            if lofn < hifn {
                ans[ilo] = lofn
                ilo++
                lo++
            } else {
                ans[ilo] = hifn
                ilo++
                hi--
            }
        }
    }
    
    return ans
}

func fn(a, b, c, x int) int {
    return a * x * x + b * x + c
}