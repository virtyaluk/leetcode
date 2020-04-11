package main
func maxProfit(prices []int) int {
    if len(prices) < 2 {
        return 0
    }
    
    maxProfit, minPrice := 0, prices[0]
    
    for _, p := range prices {
        if p - minPrice > maxProfit {
            maxProfit = p - minPrice
        }
        
        if p < minPrice {
            minPrice = p
        }
    }
    
    return maxProfit
}
