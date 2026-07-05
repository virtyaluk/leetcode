class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int ans = INT_MAX;

        for (int i = -1, j = -1, idx = 0; idx < size(nums); idx++) {
            if (nums[idx] == 1) {
                i = idx;
            } else if (nums[idx] == 2) {
                j = idx;
            }

            if (i != -1 and j != -1) {
                ans = min(ans, abs(i - j));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};