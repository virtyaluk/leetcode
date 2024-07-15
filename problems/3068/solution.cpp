class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ans = 0;
        int cnt = 0,
            posMin = 1 << 30,
            negMax = -1 * (1 << 30);
        
        for (const int& num: nums) {
            int val = num ^ k,
                dif = val - num;
            ans += num;
            
            if (dif > 0) {
                posMin = min(posMin, dif);
                ans += dif;
                cnt++;
            } else {
                negMax = max(negMax, dif);
            }
        }
        
        if (cnt % 2 == 0) {
            return ans;
        }
        
        return max(ans - posMin, ans + negMax);
    }
};