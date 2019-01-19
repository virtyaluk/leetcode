import "sort"

func threeSum(nums []int) [][]int {
    ans := [][]int{}
    
    sort.Ints(nums)
    
    for i := 0; i < len(nums) - 2; i++ {
        // Skip duplicate a
        if i > 0 && nums[i] == nums[i - 1] {
            continue
        }
        
        a, lo, hi := nums[i], i + 1, len(nums) - 1
        
        for lo < hi {
            b, c := nums[lo], nums[hi]
            curSum := a + b + c
            
            if curSum == 0 {
                ans = append(ans, []int{a, b, c})
                
                // Skip duplicate b
                for lo < hi && nums[lo] == nums[lo + 1] {
                    lo++
                }
                
                // Skip duplicate b
                for lo < hi && nums[hi] == nums[hi - 1] {
                    hi--
                }
                
                lo++
                hi--
            } else if curSum > 0 {
                hi--
            } else {
                lo++
            }
        }
    }
    
    return ans
}