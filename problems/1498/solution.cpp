const int MOD = 1e9 + 7;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = size(nums), ans = 0;
        vector<long int> pows(n, 1);
        
        for (int i = 1; i < n; i++) {
            pows[i] = pows[i - 1] * 2 % MOD;
        }
        
        sort(begin(nums), end(nums));
        
        for (int i = 0, j = n - 1; i <= j;) {
            if (nums[i] + nums[j] <= target) {
                ans = (ans + pows[j - i]) % MOD;
                i++;
            } else {
                j--;
            }
        }
        
        return ans;
    }
};