class Bank {
private:
    vector<long long> b;
    int n;

    bool isValid(int acc, long long m) {
        return acc >= 1 and acc <= n and b[acc - 1] >= m;
    }
public:
    Bank(vector<long long>& balance): b{balance} {
        n = size(balance);
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (not isValid(account1, money)) {
            return false;
        }
        
        if (not isValid(account2, -1)) {
            return false;
        }
        
        b[account1 - 1] -= money;
        b[account2 - 1] += money;
        
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (not isValid(account, -1)) {
            return false;
        }
        
        b[account - 1] += money;
        
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (not isValid(account, money)) {
            return false;
        }
        
        b[account - 1] -= money;
        
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */