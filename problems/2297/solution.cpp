class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& costs) {
        vector<long long> dp(size(nums), LLONG_MAX);
        stack<int> first, second;
        dp[0] = 0;
        
        for (int i = 0; i < size(nums); i++) {
            while (not empty(first) and nums[i] >= nums[first.top()]) {
                dp[i] = min(dp[i], dp[first.top()] + costs[i]);
                first.pop();
            }
            
            while (not empty(second) and nums[i] < nums[second.top()]) {
                dp[i] = min(dp[i], dp[second.top()] + costs[i]);
                second.pop();
            }
            
            first.push(i);
            second.push(i);
        }
        
        return dp.back();
    }
};