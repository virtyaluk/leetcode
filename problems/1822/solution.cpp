class Solution {
public:
    int arraySign(vector<int>& nums) {
        if (nums.front() == 0) {
            return 0;
        }
        
        int ans = nums.front() > 0 ? 1 : -1;
        
        for (int i = 1; i < size(nums); i++) {
            if (nums[i] == 0) {
                return 0;
            }
            
            ans *= (nums[i] > 0 ? 1 : -1);
        }
        
        return ans > 0 ? 1 : -1;
    }
};