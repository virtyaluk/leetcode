class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        
        vector<int> sieve(n + 1, true);
        
        for (int i = 2; i * i <= n; i++) {
            if (sieve[i]) {
                for (int j = i * i; j <= n; j += i) {
                    sieve[j] = false;
                }
            }
        }
        
        return count(begin(sieve) + 2, end(sieve) - 1, true);
    }
};