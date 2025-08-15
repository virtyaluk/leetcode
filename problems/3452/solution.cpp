class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int ans = 0,
            n = size(nums);
        
        for (int i = 0; i < n; i++) {
            if (
                (i - k >= 0 and i + k < n and nums[i] > nums[i - k] and nums[i] > nums[i + k])
                or
                (i - k >= 0 and i + k >= n and nums[i] > nums[i - k])
                or
                (i + k < n and i - k < 0 and nums[i] > nums[i + k])
                or
                (i - k < 0 and i + k >= n)
            ) {
                ans += nums[i];
            }
        }

        return ans;
    }
};