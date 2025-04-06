class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int ans = 0,
            median = 0;
        vector<int> nums;

        for (const vector<int>& row: grid) {
            for (const int& cell: row) {
                nums.push_back(cell);
            }
        }

        sort(begin(nums), end(nums));

        median = nums[size(nums) / 2];

        for (const int& num: nums) {
            if (num % x != median % x) {
                return -1;
            }

            ans += abs(median - num) / x;
        }

        return ans;
    }
};