class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = size(nums);
        long long cur = 0;
        vector<int> ans(n, -1);
        
        for (int i = 0; i < n; i++) {
            cur += nums[i];
            
            if (i - k - k - 1 >= 0) {
                cur -= nums[i - k - k - 1];
            }
            
            if (i - k - k >= 0) {
                ans[i - k] = cur / (k + k + 1);
            }
        }
        
        return ans;
    }
};