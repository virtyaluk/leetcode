const int MOD = 1e9 + 7;

class Solution {
private:
    long long power(long long x, long long n) {
        if (not n) {
            return 1;
        }
        
        long long ans = power(x, n / 2);
        ans *= ans;
        ans %= MOD;
        
        if (n % 2 == 1) {
            ans *= x;
            ans %= MOD;
        }
        
        return ans;
    }

public:
    int countGoodNumbers(long long n) {
        long long numberOfOddPlaces = n / 2,
            numberOfEvenPlaces = n / 2 + n % 2;
        
        return (power(5, numberOfEvenPlaces) * power(4, numberOfOddPlaces)) % MOD;
    }
};
