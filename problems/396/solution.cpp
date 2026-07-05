class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int f = 0,
            n = size(nums),
            numSum = accumulate(begin(nums), end(nums), 0);

        for (int i = 0; i < n; i++) {
            f += i * nums[i];
        }

        int ans = f;

        for (int i = n - 1; i > 0; i--) {
            f += numSum - n * nums[i];
            ans = max(ans, f);
        }

        return ans;
    }
};