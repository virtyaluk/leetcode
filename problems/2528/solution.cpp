class Solution {
private:
    bool check(vector<long long>& freq, const int& r, const int& k, const int& n, long long val) {
        long long sum = 0,
            rem = k;
        vector<long long> diff = freq;

        for (int i = 0; i < n; i++) {
            sum += diff[i];

            if (sum < val) {
                long long add = val - sum;

                if (rem < add) {
                    return false;
                }

                rem -= add;
                int end = min(n, i + 2 * r + 1);
                diff[end] -= add;
                sum += add;
            }
        }

        return true;
    }
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        long long ans = 0,
            lo = ranges::min(stations),
            hi = accumulate(begin(stations), end(stations), 0ll) + k;
        int n = size(stations);
        vector<long long> freq(n + 1);

        for (int i = 0; i < n; i++) {
            int left = max(0, i - r),
                right = min(n, i + r + 1);
            freq[left] += stations[i];
            freq[right] -= stations[i];
        }

        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;

            if (check(freq, r, k, n, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};