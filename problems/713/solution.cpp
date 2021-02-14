class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0, left = 0, prod = 1;
        
        for (int right = 0; right < nums.size(); right++) {
            prod *= nums[right];
            
            while (prod >= k && left <= right) {
                prod /= nums[left++];
            }
            
            ans += right - left + 1;
        }
        
        return ans;
    }
};