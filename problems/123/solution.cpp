class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice1 = INT_MAX,
            minPrice2 = INT_MAX,
            profit1 = 0,
            profit2 = 0;
        
        for (const int& price: prices) {
            minPrice1 = min(minPrice1, price);
            profit1 = max(profit1, price - minPrice1);
            
            minPrice2 = min(minPrice2, price - profit1);
            profit2 = max(profit2, price - minPrice2);
        }
        
        return profit2;
    }
    
    int maxProfit2(vector<int>& prices) {
        if (size(prices) <= 1) {
            return 0;
        }
        
        int n = size(prices), ans = 0;
        vector<int> left(n), right(n + 1);
        
        for (int i = 1, leftMin = prices.front(), rightMax = prices.back(); i < n; i++) {
            left[i] = max(left[i - 1], prices[i] - leftMin);
            leftMin = min(leftMin, prices[i]);
            
            int j = n - i - 1;
            right[j] = max(right[j + 1], rightMax - prices[j]);
            rightMax = max(rightMax, prices[j]);
        }
        
        for (int i = 0; i < n; i++) {
            ans = max(ans, left[i] + right[i + 1]);
        }
        
        return ans;
    }
    
    int maxProfit1(vector<int>& prices) {
        int ans = 0;
        
        for (int i = 0; i < size(prices); i++) {
            ans = max(ans, getProfit(prices, 0, i) + getProfit(prices, i, size(prices)));
        }
        
        return ans;
    }
    
    int getProfit(vector<int>& prices, int lo, int hi) {
        int ans = 0, minPrice = INT_MAX;
        
        for (int i = lo; i < hi; i++) {
            ans = max(ans, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        
        return ans;
    }
};