class StockPrice {
private:
    multiset<int> prices;
    map<int, int> history;
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if (history.contains(timestamp)) {
            int oldPrice = history[timestamp];

            prices.extract(oldPrice);
        }

        history[timestamp] = price;
        prices.insert(price);
    }
    
    int current() {
        return (*rbegin(history)).second;
    }
    
    int maximum() {
        return *rbegin(prices);
    }
    
    int minimum() {
        return *begin(prices);
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */