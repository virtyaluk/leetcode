class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int ans = 0;

        for (int i = 1, cur = 1, prev = 0; i < size(nums); i++) {
            if (nums[i] > nums[i - 1]) {
                cur++;
            } else {
                prev = cur;
                cur = 1;
            }

            ans = max(ans, min(prev, cur));
            ans = max(ans, cur / 2);
        }

        return ans;
    }
};