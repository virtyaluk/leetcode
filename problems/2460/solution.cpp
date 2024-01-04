class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for (int i = 0; i < size(nums) - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        
        int j = 0;
        
        for (int i = 0; i < size(nums); i++) {
            nums[j] = nums[i];
            
            if (nums[j]) {
                j++;
            }
        }
        
        while (j < size(nums)) {
            nums[j++] = 0;
        }
        
        return nums;
    }
};