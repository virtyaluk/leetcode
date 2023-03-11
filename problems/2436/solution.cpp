class Solution {
public:
    int minimumSplits(vector<int>& nums) {
        int ans = 1,
            g = nums.front();
        
        for (int i = 1; i < size(nums); i++) {
            if (gcd(g, nums[i]) == 1) {
                ans++;
                g = nums[i];
            } else {
                g = gcd(g, nums[i]);
            }
        }
        
        return ans;
    }
};