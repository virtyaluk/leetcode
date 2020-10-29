class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        
        if (sum % 2 == 1) {
            return false;
        }
        
        sum /= 2;
        
        vector<bool> dp(sum + 1);
        dp[0] = true;
        
        for (const int& num: nums) {
            // for (int i = num; i <= sum; i++) {
            //     dp[i] = dp[i] || dp[i - num];
            // }
            
            for (int i = sum; i >= num; i--) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        // [0,1,2,3,4,5,6,7,8,9,10,11]
        // [+,+,+,+,+,+,+,+,+,+, +, +]
        // [+,+,-,-,-,+,+,-,-,-, +, +]
        
        return dp[sum];
    }
    
    bool dfs(const vector<int>& nums, const int& sum, int curSum, const int i) {
        curSum += nums[i];
        
        if (curSum == sum) {
            return true;
        }
        
        for (int j = i + 1; j < nums.size(); j++) {
            if (dfs(nums, sum, curSum, j)) {
                return true;
            }
        }
        
        return false;
    }
    
    bool canPartition1(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if (sum % 2 != 0) {
            return false;
        }
        
        int subsetSum = sum / 2;
        vector<bool> dp(subsetSum + 1);
        dp[0] = true;
        
        for (int num: nums) {
            for (int i = subsetSum; i >= num; i--) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        
        return dp[subsetSum];
    }
};