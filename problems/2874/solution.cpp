class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int n = size(nums);
        vector<int> leftMax(n, INT_MIN),
            rightMax(n, INT_MIN);
        
        for (int i = 0, m = INT_MIN; i < n; i++) {
            m = max(m, nums[i]);
            leftMax[i] = m;
        }
        
        for (int i = n - 1, m = INT_MIN; i >= 0; i--) {
            m = max(m, nums[i]);
            rightMax[i] = m;
        }

        for (int j = 1; j < n - 1; j++) {
            long long cur = ((long long) leftMax[j - 1] - (long long) nums[j]) * (long long) rightMax[j + 1];
            ans = max(ans, cur);
        }

        return ans;
    }
};