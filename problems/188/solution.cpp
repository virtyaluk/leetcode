class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = size(prices);
        vector<int> minPrice(k + 1, INT_MAX), profit(k + 1);
        
//         if (k >= n / 2) {
//             int ans = 0;
            
//             for (int i = 1; i < n; i++) {
//                 ans += max(0, prices[i] - prices[i - 1]);
//             }
//         }
        
        for (const int& price: prices) {
            for (int i = 1; i <= k; i++) {
                profit[i] = max(profit[i], price - minPrice[i]);
                minPrice[i] = min(minPrice[i], price - profit[i - 1]);
            }
        }
        
        return profit[k];
    }
};