class Solution {
private:
    bool check(vector<int>& ranks, int cars, long long r) {
        long long ans = 0;

        for (const int& rank: ranks) {
            ans += sqrt(1.0 * r / rank);
        }

        return ans < cars;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long lo = 1,
            hi = 1ll * cars * cars * ranks.front(),
            mid;

        while (lo < hi) {
            mid = (lo + hi) / 2;

            if (check(ranks, cars, mid)) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        return lo;
    }
};