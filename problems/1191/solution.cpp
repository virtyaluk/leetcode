const int MOD = 1e9 + 7;

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long n = size(arr),
            total = accumulate(begin(arr), end(arr), 0ll),
            sum = 0,
            curSum = 0;
        
        for (int i = 0; i < n * min(k, 2); i++) {
            curSum = max<long long>(curSum + arr[i % n], arr[i % n]);
            sum = max(sum, curSum);
        }

        return max<long long>({0, sum, sum + total * max(0, k - 2)}) % MOD;
    }
};