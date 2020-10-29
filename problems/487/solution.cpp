class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left, zero, ans;
        left = 0, zero = -1, ans = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                if (zero != -1) {
                    left = zero + 1;
                }
                
                zero = right;
            }
            
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};