class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        long long ans = 0;
        unordered_map<double, int> um;

        for (int r = 4; r < size(nums) - 2; r++) {
            int q = r - 2;

            for (int p = 0; p < q - 1; p++) {
                um[1.0 * nums[p] / nums[q]]++;
            }

            for (int s = r + 2; s < size(nums); s++) {
                ans += um[1.0 * nums[s] / nums[r]];
            }
        }

        return ans;
    }
};