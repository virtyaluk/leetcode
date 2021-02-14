package main
func partitionLabels(S string) []int {
    lastSeen, ans := make(map[rune]int), []int{}
    
    for i, ch := range S {
        lastSeen[ch] = i
    }
    
    partStart, partEnd := 0, 0

    for i, ch := range S {
        partEnd = max(partEnd, lastSeen[ch])
        
        if i == partEnd {
            ans = append(ans, partEnd - partStart + 1)
            partStart = i + 1
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