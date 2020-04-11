package main
const MaxInt = int(^uint(0) >> 1)

func maxProfit(prices []int) int {
    t1cost, t2cost, t1profit, t2profit := MaxInt, MaxInt, 0, 0
    
    for _, price := range prices {
        t1cost = min(t1cost, price)
        t1profit = max(t1profit, price - t1cost)
        
        t2cost = min(t2cost, price - t1profit)
        t2profit = max(t2profit, price - t2cost)
    }
    
    return t2profit
}

func min(a, b int) int {
    if a < b { return a }
    return b
}

func max(a, b int) int {
    if a > b { return a }
    return b
}