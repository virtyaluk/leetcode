class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long ans = 0,
            rsum = accumulate(begin(nums), end(nums), 0ll),
            lsum = 0;

        for (int i = 0; i < size(nums) - 1; i++) {
            lsum += nums[i];
            rsum -= nums[i];
            ans += lsum >= rsum;
        }

        return ans;
    }
};