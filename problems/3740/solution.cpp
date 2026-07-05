class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = INT_MAX;
        unordered_map<int, vector<int>> um;

        for (int i = 0; i < size(nums); i++) {
            um[nums[i]].push_back(i);
        }

        for (auto [_, nums]: um) {
            if (size(nums) < 3) {
                continue;
            }

            for (int idx = 2; idx < size(nums); idx++) {
                int i = nums[idx - 2],
                    j = nums[idx - 1],
                    k = nums[idx];

                ans = min(
                    ans,
                    abs(i - j) + abs(j - k) + abs(k - i)
                );
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};