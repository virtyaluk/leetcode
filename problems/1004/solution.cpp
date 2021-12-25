class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, cur = 0, n = size(nums);
        
        for (int left = 0, right = 0; right < n; right++) {
            if (nums[right] == 0) {
                cur++;
            }
            
            while (cur > k) {
                if (nums[left] == 0) {
                    cur--;
                }
                
                left++;
            }
            
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};