class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = size(nums),
            cnt = n;
        long long ans = 0,
            preSum = 0;
        vector<int> pre(n * 2 + 1);
        pre[n] = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                preSum += pre[cnt];
                cnt++;
                pre[cnt]++;
            } else {
                cnt--;
                preSum -= pre[cnt];
                pre[cnt]++;
            }

            ans += preSum;
        }

        return ans;
    }
};