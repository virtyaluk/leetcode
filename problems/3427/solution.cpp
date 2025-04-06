class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < size(nums); i++) {
            for (int j = max(0, i - nums[i]); j <= i; j++) {
                ans += nums[j];
            }
        }

        return ans;
    }
};