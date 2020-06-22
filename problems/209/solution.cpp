class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ans = INT_MAX, left = 0, cur = 0, n = nums.size();
        
        for (int i = 0; i < n; i++) {
            cur += nums[i];
            
            while (cur >= s) {
                ans = min(ans, i + 1 - left);
                cur -= nums[left++];
            }
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};