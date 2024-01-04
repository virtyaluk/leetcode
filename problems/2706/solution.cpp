class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(begin(prices), end(prices));
        
        if (size(prices) < 2 or money - (prices[0] + prices[1]) < 0) {
            return money;
        }
        
        return money - (prices[0] + prices[1]);
    }
};