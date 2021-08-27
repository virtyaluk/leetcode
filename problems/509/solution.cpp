class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        
        int n1 = 0, n2 = 1;
        
        for (int i = 2; i < n; i++) {
            int tmp = n1 + n2;
            n1 = n2;
            n2 = tmp;
        }
        
        return n1 + n2;
    }
    
    int fib2(int n) {
        if (n <= 1) {
            return n;
        }
        
        vector<int> dp(n + 1);
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
    
    unordered_map<int, int> memo;

    int fib1(int n) {
        if (n <= 1) {
            return n;
        }
        
        if (memo.count(n)) {
            return memo[n];
        }
        
        return memo[n] = fib(n - 1) + fib(n - 2);
    }
};