class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long int ans = 0, i = 0, miss = 1;
        
        while (miss <= n) {
            if (i < size(nums) and nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss += miss;
                ans++;
            }
        }
        
        return ans;
    }
};