class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int minPrice = -prices.front(), profit = 0;
        
        for (int i = 1; i < size(prices); i++) {
            profit = max(profit, minPrice + prices[i] - fee);
            minPrice = max(minPrice, profit - prices[i]);
        }
        
        return profit;
    }
};

/*

   1  3  2  8  4  9
b -1  
s  0  
*/