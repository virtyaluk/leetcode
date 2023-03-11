class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        long long ans = 1;
        
        for (long long i = 1, cnt = 1; i < size(nums); i++) {
            if (nums[i] > nums[i - 1]) {
                cnt++;
            } else {
                cnt = 1;
            }
            
            ans += cnt;
        }
        
        return ans;
    }
};