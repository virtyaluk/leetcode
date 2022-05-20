package main
func kidsWithCandies(candies []int, extraCandies int) []bool {
    max, ans := 0, make([]bool, len(candies))
    
    for i := range candies {
        if candies[i] > max {
            max = candies[i]
        }
    }
    
    for i := range ans {
        if candies[i] + extraCandies >= max {
            ans[i] = true
        }
    }
    
    return ans
}