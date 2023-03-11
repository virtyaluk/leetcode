class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0,
            cnt = 0;
        
        for (const int& num: nums) {
            if (num) {
                cnt = 0;
            } else {
                ans += ++cnt;
            }
        }
        
        return ans;
    }
};