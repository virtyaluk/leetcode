class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        if (nums.size() == 1) {
            return nums[0];
        }
        
        return max(robSub(nums, 0, nums.size() - 2), robSub(nums, 1, nums.size() - 1));
    }
    
    int robSub(vector<int>& nums, int start, int end) {
        int t1 = 0, t2 = 0;
        
        for (int i = start; i <= end; i++) {
            int tmp = t1;
            t1 = max(nums[i] + t2, t1);
            t2 = tmp;
        }
        
        return t1;
    }
};