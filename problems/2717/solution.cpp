class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int m = -1, M = -1;
        
        for (int i = 0; i < size(nums); i++) {
            if (nums[i] == 1) {
                m = i;
            } else if (nums[i] == size(nums)) {
                M = i;
            }
        }
        
        return m > M ? m + size(nums) - 1 - M - 1 : m + size(nums) - M - 1;
    }
};