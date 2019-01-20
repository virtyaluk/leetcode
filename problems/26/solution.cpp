class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (empty(nums)) {
            return 0;
        }
        
        int j = 1;
        
        for (int i = 1; i < size(nums); i++) {
            nums[j] = nums[i];
            
            if (nums[j] != nums[j - 1]) {
                j++;
            }
        }
        
        return j;
    }
};