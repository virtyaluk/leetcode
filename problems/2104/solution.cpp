class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        
        for (int i = 0; i < size(nums); i++) {
            int m = nums[i],
                M = nums[i];
            
            for (int j = i + 1; j < size(nums); j++) {
                m = min(m, nums[j]);
                M = max(M, nums[j]);
                ans += M - m;
            }
        }
        
        return ans;
    }
};