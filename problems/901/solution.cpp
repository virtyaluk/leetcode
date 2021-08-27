class StockSpanner {
private:
    vector<int> prices = {INT_MAX};
    stack<int> st;
public:
    StockSpanner() {
        st.push(0);
    }
    
    int next(int price) {
        prices.push_back(price);
        
        while (prices[st.top()] <= price) {
            st.pop();
        }
        
        int ans = size(prices) - 1 - st.top();
        
        st.push(size(prices) - 1);
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

/*

[100,80,60,70,60,75,85]

100, 80, 60, _, 60, _, _


*/