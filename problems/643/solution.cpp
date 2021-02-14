class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = 0.0, cur = 0.0;
        
        for (int i = 0; i < k; i++) {
            cur += nums[i];
        }
        
        ans = cur;
        
        for (int i = k ; i < size(nums); i++) {
            cur += nums[i];
            cur -= nums[i - k];
            ans = max(ans, cur);
        }
        
        return ans / (double) k;
    }
};