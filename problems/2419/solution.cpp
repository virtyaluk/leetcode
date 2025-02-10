class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0,
            curMax = 0,
            curStreak = 0;
        
        for (const int& num: nums) {
            if (curMax < num) {
                curMax = num;
                ans = curStreak = 0;
            }
            
            if (curMax == num) {
                curStreak++;
            } else {
                curStreak = 0;
            }
            
            ans = max(ans, curStreak);
        }
        
        return ans;
    }
};