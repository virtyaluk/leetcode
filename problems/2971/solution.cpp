class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long ans = accumulate(begin(nums), end(nums), 0ll);
        
        sort(begin(nums), end(nums));
        
        for (int i = size(nums) - 1; i >= 0; i--) {
            if (ans - nums[i] > nums[i]) {
                return ans;
            }
            
            ans -= nums[i];
        }
        
        return -1;
    }
};