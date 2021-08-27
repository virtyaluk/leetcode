class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int ans = 0;
        
        sort(begin(nums), end(nums));
        
        for (int i = 1; i < size(nums); i++) {
            if (nums[i] <= nums[i - 1]) {
                ans += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }
        
        return ans;
    }
};

// 3,2,1,2,1,7
// 1, 1, 2, 2, 3, 7
// 1, 2, 3