class Solution {
public:
    int constrainedSubsetSum1(vector<int>& nums, int k) {
        int n = size(nums), ans = INT_MIN;
        vector<int> dp(n, INT_MIN);
        
        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
            
            for (int j = max(0, i - k); j < i; j++) {
                dp[i] = max(dp[i], nums[i] + dp[j]);
            }
            
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
    
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int ans = nums.front();
        priority_queue<pair<int, int>> pq;
        
        pq.push({nums.front(), 0});
        
        for (int j = 1; j < size(nums); j++) {
            while (not empty(pq) and pq.top().second < j - k) {
                pq.pop();
            }
            
            auto num = max(nums[j], pq.top().first + nums[j]);
            ans = max(ans, num);
            
            pq.push({num, j});
        }
        
        return ans;
    }
};