class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int ans = 0,
            n = size(nums);
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    ans += (nums[i] != nums[j] and nums[j] != nums[k] and nums[i] != nums[k]);
                }
            }
        }
        
        return ans;
    }
};