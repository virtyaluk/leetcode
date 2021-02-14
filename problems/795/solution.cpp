class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0,
            n = size(nums),
            lo = -1,
            hi = -1;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > right) {
                lo = i;
            }
            
            if (nums[i] >= left) {
                hi = i;
            }
            
            ans += hi - lo;
        }
        
        return ans;
    }
    
    int numSubarrayBoundedMax1(vector<int>& nums, int left, int right) {
        int ans = 0,
            n = size(nums);
        
        for (int i = 0; i < n; i++) {
            int cur = nums[i];

            for (int j = i; j < n; j++) {
                cur = max(cur, nums[j]);
                
                if (cur > right) {
                    break;
                }
                
                if (cur >= left and cur <= right) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};