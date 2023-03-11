class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int rightSum = accumulate(begin(nums), end(nums), 0);
        
        for (int i = 0, leftSum = 0; i < size(nums); i++) {
            rightSum -= nums[i];
            
            if (rightSum == leftSum) {
                return i;
            }
            
            leftSum += nums[i];
        }
        
        return -1;
    }
};