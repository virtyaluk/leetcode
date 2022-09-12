#define ll long long int
const int MOD = 1e9 + 7;

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size(), idx1 = 1, idx2 = 1;
        ll ans = 0, cur = 0, sum = accumulate(nums.begin(), nums.end(), 0), sum1 = nums[0], sum2 = nums[0];
        
        for (int i = 0; i < n; i++) {
            cur += nums[i];
            ll right = sum - cur;
            
            if (i == 0 || i == n - 1) {
                continue;
            }
            
            while (idx1 <= i && 2 * sum1 <= cur) {
                sum1 += nums[idx1++];
            }
            
            while (idx2 < idx1 && cur - sum2 > right) {
                sum2 += nums[idx2++];
            }
            
            if (idx1 > idx2) {
                ans += (idx1 - idx2);
                ans %= MOD;
            }
        }
        
        return ans;
    }
};