class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        long long int ans = 0,
            i = 0,
            j = size(nums) - 1,
            si = nums[i],
            sj = nums[j];
        
        while (i < j) {
            if (si == sj) {
                si = nums[++i];
                sj = nums[--j];
            } else if (si < sj) {
                si += nums[++i];
                ans++;
            } else {
                sj += nums[--j];
                ans++;
            }
        }
        
        return ans;
    }
};