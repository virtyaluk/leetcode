class Solution {
private:
    void ins(int price, int profit, map<int, int>& m) {
        auto it = m.upper_bound(price);
        
        if (it != begin(m) and (--it)->second >= profit) {
            return;
        }
        
        for (it = m.lower_bound(price); it != end(m) and it->second <= profit; m.erase(it++));
        
        m[price] = profit;
    }
public:
    int maxProfit(vector<int>& prices, vector<int>& profits) {
        int ans = -1;
        map<int, int> one, two;
        
        for (int i = 0; i < size(prices); i++) {
            auto it = two.lower_bound(prices[i]);
            
            if (it != begin(two)) {
                ans = max(ans, profits[i] + (--it)->second);
            }
            
            it = one.lower_bound(prices[i]);
            
            if (it != begin(one)) {
                ins(prices[i], (--it)->second + profits[i], two);
            }
            
            ins(prices[i], profits[i], one);
        }
        
        return ans;
    }
};