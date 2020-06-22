package main
const MaxInt = int(^uint(0) >> 1)
const MinInt = -MaxInt - 1

func maxProfit(prices []int) int {
    coolDown, sell, hold := 0, 0, MinInt
    
    for _, price := range prices {
        prevCoolDown, prevSell, prevHold := coolDown, sell, hold
        
        coolDown = max(prevCoolDown, prevSell)
        sell = prevHold + price
        hold = max(prevHold, prevCoolDown - price)
    }
    
    return max(sell, coolDown)
}

func max(a, b int) int {
    if a > b { return a }
    return b
}