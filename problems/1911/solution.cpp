class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long ans = nums.front();
        
        for (int i = 1; i < size(nums); i++) {
            ans += max(nums[i] - nums[i-1], 0);
        }
        
        return ans;
    }
};