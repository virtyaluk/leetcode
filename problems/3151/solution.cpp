class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 1; i < size(nums); i++) {
            int par = nums[i - 1] % 2;
            par += nums[i] % 2;
            
            if (par == 0 or par == 2) {
                return false;
            }
        }
        
        return true;
    }
};