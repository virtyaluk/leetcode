class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = size(nums),
            p,
            q,
            j;
        long long ans = LLONG_MIN,
            maxSum,
            sum,
            res;
        
        for (int i = 0; i < n; i++) {
            j = i + 1;
            res = 0;

            for (; j < n and nums[j - 1] < nums[j]; j++);

            p = j - 1;

            if (p == i) {
                continue;
            }

            res += nums[p] + nums[p - 1];

            for (; j < n and nums[j - 1] > nums[j]; j++) {
                res += nums[j];
            }

            q = j - 1;

            if (q == p or q == n - 1 or (nums[j] <= nums[q])) {
                i = q;
                continue;
            }

            res += nums[q + 1];
            maxSum = 0;
            sum = 0;

            for (int k = q + 2; k < n and nums[k] > nums[k - 1]; k++) {
                sum += nums[k];
                maxSum = max(maxSum, sum);
            }

            res += maxSum;
            maxSum = 0;
            sum = 0;

            for (int k = p - 2; k >= i; k--) {
                sum += nums[k];
                maxSum = max(maxSum, sum);
            }

            res += maxSum;
            ans = max(ans, res);
            i = q - 1;
        }

        return ans;
    }
};