class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < size(nums); i++) {
            if (i % 2 == 0) {
                ans += nums[i];
            } else {
                ans -= nums[i];
            }
        }

        return ans;
    }
};