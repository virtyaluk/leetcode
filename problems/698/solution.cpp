class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(begin(nums), end(nums), 0);
        
        if (sum % k != 0) {
            return false;
        }
        
        sum /= k;
        
        if (*max_element(begin(nums), end(nums)) > sum) {
            return false;
        }
        
        return backtrack(nums, k, sum, 0, 0);
    }
    
    bool backtrack(vector<int>& nums, int k, const int sum, int curSum, int i) {
        if (k == 1) {
            return true;
        }
        
        if (sum == curSum) {
            return backtrack(nums, k - 1, sum, 0, 0);
        }
        
        for (int j = i; j < nums.size(); j++) {
            if (nums[j] > 0 and curSum + nums[j] <= sum) {
                nums[j] *= -1;
                
                if (backtrack(nums, k, sum, curSum + nums[j] * -1, i + 1)) {
                    return true;
                }
                
                nums[j] *= -1;
            }
        }
        
        return false;
    }
};