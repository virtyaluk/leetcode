class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        int M = 0, idx = -1;
        vector<int> ans;
        
        for (int i = 0; i < nums.size() - k + 1; i++) {
            if (nums[i] > M) {
                M = nums[i];
                idx = i;
            }
        }
        
        for (int i = 0; i < k; i++) {
            ans.push_back(nums[idx + i]);
        }
        
        return ans;
    }
};