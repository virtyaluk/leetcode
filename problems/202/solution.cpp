class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        
        while (n != 1 && s.find(n) == s.end()) {
            s.insert(n);
            n = calc(n);
        }
        
        return s.find(n) == s.end();
    }
    
    int calc(int n) {
        int sum = 0;
        
        while (n > 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        
        return sum;
    }
};