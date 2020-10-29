class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        long long int ans = 0, n = size(nums);
        vector<unordered_map<long long int, int>> cnt(n);
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long int delta = (long long int) nums[i] - (long long int) nums[j],
                    sum = 0;
                
                if (cnt[j].find(delta) != end(cnt[j])) {
                    sum = cnt[j][delta];
                }
                
                cnt[i][delta] += sum + 1;
                ans += sum;
            }
        }
        
        return ans;
    }
};