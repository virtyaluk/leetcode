class Solution {
    public int maxProfit(int[] prices) {
        int cash = 0, hold = -prices[0];
        
        for (int i = 1; i < prices.length; i++) {
            cash = Math.max(cash, hold + prices[i]);
            hold = Math.max(hold, cash - prices[i]);
        }
        
        return cash;
    }
}