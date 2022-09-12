package main
func minOperations(boxes string) []int {
    n, ans := len(boxes), make([]int, len(boxes))
    
    for i, count, moves := 0, 0, 0; i < n; i++ {
        ans[i] = moves
        count += isOne(boxes[i])
        moves += count
    }
    
    for i, count, moves := n - 1, 0, 0; i >= 0; i-- {
        ans[i] += moves
        count += isOne(boxes[i])
        moves += count
    }
    
    return ans
}

func isOne(r byte) int {
    if (r == '1') {
        return 1
    }
    
    return 0
}