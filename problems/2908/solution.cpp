class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int ans = INT_MAX;
        
        for (int i = 0; i < size(nums); i++) {
            for (int j = i + 1; j < size(nums); j++) {
                for (int k = j + 1; k < size(nums); k++) {
                    if (nums[i] < nums[j] and nums[k] < nums[j]) {
                        ans = min(ans, nums[i] + nums[j] + nums[k]);
                    }
                }
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};