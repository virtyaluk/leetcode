class Cashier {
private:
    unordered_map<int, int> um;
    int customer = 0,
        _n = 0;
    double _d = 0.0;

public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        for (int i = 0; i < size(products); i++) {
            um[products[i]] = prices[i];
        }
        
        _n = n;
        _d = discount;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double bill = 0.0;
        
        for (int i = 0; i < size(product); i++) {
            bill += um[product[i]] * amount[i];
        }
        
        customer++;
        
        if (customer % _n == 0) {
            bill = bill * ((100.0 - _d) / 100.0);
        }
        
        return bill;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */