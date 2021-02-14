class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int idx = -1;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                if (idx == -1) {
                    idx = i;
                } else {
                    return false;
                }
            }
        }
        
        if (idx <= 0 or idx >= nums.size() - 2) {
            return true;
        }
        
        return nums[idx - 1] <= nums[idx + 1] or nums[idx] <= nums[idx + 2];
    }
};