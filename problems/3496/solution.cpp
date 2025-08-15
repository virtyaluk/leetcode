class Solution {
public:
    int maxScore(vector<int>& nums) {
        if (size(nums) < 2) {
            return 0;
        }

        int sum = 0,
            minVal1 = nums.front(),
            minVal2 = minVal1 + nums[1];
        
        for (int i = 0; i < size(nums); i++) {
            sum += nums[i];
            minVal1 = min(minVal1, nums[i]);

            if (i > 0) {
                minVal2 = min(minVal2, nums[i] + nums[i - 1]);
            }
        }

        if (size(nums) % 2 == 0) {
            return sum - minVal2;
        }

        return sum - minVal1;
    }
};