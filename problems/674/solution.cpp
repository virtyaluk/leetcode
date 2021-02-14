class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 1, cur = 1;
        
        for (int i = 1; i < size(nums); i++) {
            if (nums[i] > nums[i - 1]) {
                cur++;
            } else {
                cur = 1;
            }
            
            ans = max(ans, cur);
        }
        
        return ans;
    }
};