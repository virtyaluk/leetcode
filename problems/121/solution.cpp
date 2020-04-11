class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, minPrice = INT_MAX;
        
        for (const int& price: prices) {
            if (price > minPrice) {
                ans = max(ans, price - minPrice);
            }
            
            if (price < minPrice) {
                minPrice = price;
            }
        }
        
        return ans;
    }
};