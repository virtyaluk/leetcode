class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans = 0;

        for (int i = 1; i < size(nums) - 1; i++) {
            ans += 2 * (nums[i - 1] + nums[i + 1]) == nums[i];
        }

        return ans;
    }
};