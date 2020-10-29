class Solution {
public:
    bool find132pattern1(vector<int>& nums) {
        int minI = INT_MAX;
        
        for (int j = 0; j < nums.size() - 1; j++) {
            minI = min(minI, nums[j]);
            
            for (int k = j + 1; k < nums.size(); k++) {
                if (minI < nums[k] && nums[k] < nums[j]) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool find132pattern(vector<int>& nums) {
        if (size(nums) < 3) {
            return false;
        }
        
        int n = size(nums);
        vector<int> minNums(n);
        minNums.front() = nums.front();
        
        for (int i = 1; i < n; i++) {
            minNums[i] = min(minNums[i - 1], nums[i]);
        }
        
        for (int j = n - 1, k = n; j > 0; j--) {
            if (nums[j] <= minNums[j]) {
                continue;
            }
            
            while (k < n and nums[k] <= minNums[j]) {
                k++;
            }
            
            if (k < n and nums[k] < nums[j]) {
                return true;
            }
            
            nums[--k] = nums[j];
        }
        
        return false;
    }
};