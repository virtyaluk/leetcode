class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        for (int i = indexDifference, minIdx = 0, maxIdx = 0; i < size(nums); i++) {
            if (nums[i - indexDifference] < nums[minIdx]) {
                minIdx = i - indexDifference;
            }
    
            if (nums[i - indexDifference] > nums[maxIdx]) {
                maxIdx = i - indexDifference;
            }
        
            if (nums[i] - nums[minIdx] >= valueDifference) {
                return {minIdx, i};
            }
            
            if (nums[maxIdx] - nums[i] >= valueDifference) {
                return {maxIdx, i};
            }
        }
        
        return {-1, -1};
    }
};