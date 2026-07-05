class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = size(nums);
        vector<int> mins(n, INT_MAX);
        mins.back() = nums.back();

        for (int i = n - 2; i >= 0; i--) {
            mins[i] = min(nums[i], mins[i + 1]);
        }

        for (int i = 0, m = INT_MIN; i < n; i++) {
            m = max(m, nums[i]);

            if (m - mins[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};