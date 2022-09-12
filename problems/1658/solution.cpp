class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int ans = INT_MAX, cur = 0, left = 0, n = nums.size();
        
        for (int num: nums) {
            cur += num;
        }
        
        for (int right = 0; right < nums.size(); right++) {
            cur -= nums[right];
            
            while (left <= right && cur < x) {
                cur += nums[left++];
            }
            
            if (cur == x) {
                ans = min(ans, n - right + left - 1);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};