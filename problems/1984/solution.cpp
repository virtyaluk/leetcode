class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        
        int ans = nums[k - 1] - nums.front();
        
        for (int i = k; i < size(nums); i++) {
            ans = min(ans, nums[i] - nums[i - k + 1]);
        }
        
        return ans;
    }
};

// 1, 4, 7, 9