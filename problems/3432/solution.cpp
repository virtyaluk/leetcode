class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int ans = 0,
            sum = accumulate(begin(nums), end(nums), 0);

        for (int i = 0, cur = 0; i < size(nums) - 1; i++) {
            cur += nums[i];
            sum -= nums[i];
            ans += (cur - sum) % 2 == 0;
        }

        return ans;
    }
};