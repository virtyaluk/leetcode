vector<int> primes;

class Solution {
private:
    void sieve() {
        if (not empty(primes)) {
            return;
        }

        int maxn = pow(10, 6);
        vector<bool> siv(maxn, true);
        // primes[0] = primes[1] = false;

        for (int i = 2; i * i <= maxn; i++) {
            if (siv[i]) {
                for (int j = i * i; j < maxn; j += i) {
                    siv[j] = false;
                }
            }
        }

        for (int i = 1; i < maxn; i++) {
            if (siv[i]) {
                primes.push_back(i);
            }
        }
    }
public:
    Solution() {
        sieve();
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> ans(2, -1);
        int dif = INT_MAX,
            num1,
            num2;

        if (left == 1) {
            left++;
        }

        auto it = lower_bound(begin(primes), end(primes), left);

        while (it + 1 < end(primes) - 1 and *(it + 1) <= right and dif != 2) {
            num1 = *(it);
            num2 = *(it + 1);

            if (num2 - num1 < dif) {
                ans = {num1, num2};
                dif = num2 - num1;
            }

            it++;
        }

        return ans;
    }
};