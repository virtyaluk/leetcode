class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        int n = size(nums);

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) {
                continue;
            }

            long long numEls = ceil((nums[i] + nums[i + 1] - 1ll) / nums[i + 1]);
            ans += numEls - 1;
            nums[i] /= numEls;
        }

        return ans;
    }
};