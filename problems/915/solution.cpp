class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int ans = 1, runningMax = nums.front(), curMax = nums.front();
        
        for (int i = 0; i < size(nums); i++) {
            runningMax = max(runningMax, nums[i]);
            
            if (nums[i] < curMax) {
                curMax = runningMax;
                ans = i + 1;
            }
        }
        
        return ans;
    }
    
    int partitionDisjoint1(vector<int>& nums) {
        int n = size(nums);
        vector<int> rightMin(n);
        
        rightMin.back() = nums.back();
        
        for (int i = n - 2; i >= 0; i--) {
            rightMin[i] = min(nums[i], rightMin[i + 1]);
        }
        
        for (int i = 0, rightMax = 0; i < n - 1; i++) {
            rightMax = max(rightMax, nums[i]);
            
            if (rightMax <= rightMin[i + 1]) {
                return i + 1;
            }
        }
        
        return -1;
    }
};