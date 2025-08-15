class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;

        while (not is_sorted(begin(nums), end(nums))) {
            int n = size(nums),
                m = INT_MAX,
                idx = 0,
                sum = 0;
            
            for (int i = 0; i < n - 1; i++) {
                sum = nums[i] + nums[i + 1];

                if (sum < m) {
                    m = sum;
                    idx = i;
                }
            }

            nums[idx] = m;
            nums.erase(begin(nums) + idx + 1);
            ans++;
        }

        return ans;
    }
};