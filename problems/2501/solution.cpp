class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int ans = -1;
        set<long long> us(begin(nums), end(nums));
        
        while (not empty(us)) {
            long long num = *begin(us);
            int lngth = 0;
            
            while (us.count(num)) {
                lngth++;
                us.erase(num);
                num *= num;
            }
            
            ans = max(ans, lngth);
        }
        
        return ans > 1 ? ans : -1;
    }
};