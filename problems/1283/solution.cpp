class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, hi = 1e6;
        auto computeSum = [&](int x) {
            int sum = 0;
            
            for (int num: nums) {
                sum += num / x + (num % x == 0 ? 0 : 1);
            }
            
            return sum;
        };
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int sum = computeSum(mid);
            
            if (sum > threshold) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return lo;
    }
};