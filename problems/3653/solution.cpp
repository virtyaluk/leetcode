const int MOD = 1e9 + 7;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = size(nums),
            ans = 0;
        
        for (auto q: queries) {
            int l = q[0],
                r = q[1],
                k = q[2],
                v = q[3];

            for (int i = l; i <= r; i += k) {
                nums[i] = 1ll * nums[i] * v % MOD;
            }
        }

        for (auto num: nums) {
            ans ^= num;
        }

        return ans;
    }
};