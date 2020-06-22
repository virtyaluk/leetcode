class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            nums[j] = nums[i];
            
            if (nums[j]) {
                j++;
            }
        }
        
        while (j < nums.size()) {
            nums[j++] = 0;
        }
    }
};