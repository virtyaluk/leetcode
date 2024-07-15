class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int ans = 0;
        vector<int> nums = {0, 1};
        
        for (int i = 2; i <= 45; i++) {
            nums.push_back(nums[i - 1] + nums[i - 2]);
        }
        
        for (int i = size(nums) - 1; i >= 0 and k > 0; i--) {
            if (nums[i] <= k and (k - nums[i]) >= 0) {
                k -= nums[i];
                ans++;
            }
        }
        
        return ans;
    }
};