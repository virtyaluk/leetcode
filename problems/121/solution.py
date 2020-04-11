class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices or len(prices) < 2:
            return 0
        
        maxprofit = 0
        minprice = prices[0]
        
        for p in prices:
            maxprofit = max(maxprofit, p - minprice)
            minprice = min(minprice, p)
        
        return maxprofit