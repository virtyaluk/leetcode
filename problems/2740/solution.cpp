class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int ans = INT_MAX;
        
        sort(begin(nums), end(nums));
        
        for (int i = 1; i < size(nums); i++) {
            ans = min(ans, nums[i] - nums[i - 1]);
        }
        
        return ans;
    }
};