class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long minEl = INT_MAX,
            maxEl = 0;
        
        for (const int& num: nums) {
            minEl = min(minEl, (long long) num);
            maxEl = max(maxEl, (long long) num);
        }

        return (maxEl - minEl) * (long long) k;
    }
};