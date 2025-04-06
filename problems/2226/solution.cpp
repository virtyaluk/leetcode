class Solution {
private:
    bool check(const vector<int>& c, long long k, int x) {
        for (const int& cc: c) {
            k -= cc / x;

            if (k <= 0) {
                return true;
            }
        }

        return k <= 0;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int lo = 0,
            hi = *max_element(begin(candies), end(candies)),
            mid;

        while (lo < hi) {
            mid = (lo + hi + 1) / 2;

            if (check(candies, k, mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }

        return lo;
    }
};