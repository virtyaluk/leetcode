package main
func numPairsDivisibleBy60(time []int) int {
    ans := 0
    
    for i := 0; i < len(time) - 1; i++ {
        for j := i + 1; j < len(time); j++ {
            if (time[i] + time[j]) % 60 == 0 {
                ans++
            }
        }
    }
    
    return ans
}