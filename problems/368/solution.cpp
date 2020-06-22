class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = size(nums), idx = 0, maxVal = -1;
        vector<int> ans, dp(n), prev(n, -1);
        
        sort(begin(nums), end(nums));
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 and dp[j] + 1 >= dp[i]) {
                    dp[i] = 1 + dp[j];
                    prev[i] = j;
                }
            }
            
            if (maxVal < dp[i]) {
                maxVal = dp[i];
                idx = i;
            }
        }
        
        while (true) {
            ans.push_back(nums[idx]);
            idx = prev[idx];
            
            if (idx == -1) {
                break;
            }
        }
        
        reverse(begin(ans), end(ans));
        
        // copy(begin(dp), end(dp), ostream_iterator<int>(cout, ", ")); cout << endl;
        // copy(begin(prev), end(prev), ostream_iterator<int>(cout, ", ")); cout << endl;
        
        return ans;
    }
};