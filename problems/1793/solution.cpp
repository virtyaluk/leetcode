class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int ans = nums[k], minVal = nums[k], i = k, j = k, n = size(nums);
        
        while (i > 0 or j < n - 1) {
            if (i == 0) {
                j++;
            } else if (j == n - 1) {
                i--;
            } else if (nums[i - 1] < nums[j + 1]) {
                j++;
            } else {
                i--;
            }
            
            minVal = min({minVal, nums[i], nums[j]});
            ans = max(ans, minVal * (j - i + 1));
        }
        
        return ans;
    }
};