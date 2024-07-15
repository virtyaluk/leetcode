class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int m = INT_MAX, M = INT_MIN;
        
        for (int i = 0, sum = 0; i < size(nums); i++) {
            sum += nums[i];
            
            if (sum < 0) {
                M = max(M, sum);
                sum = 0;
            }
            
            M = max(M, sum);
        }
        
        for (int i = 0, sum = 0; i < size(nums); i++) {
            sum += nums[i];
            
            if (sum >= 0) {
                m = min(m, sum);
                sum = 0;
            }
            
            m = min(m, sum);
        }
        
        return max(M, abs(m));
    }
};