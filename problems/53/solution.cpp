class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0, curMax = INT_MIN;
        
        for (const int& num: nums) {
            cur = max(num, cur + num);
            curMax = max(curMax, cur);
        }
        
        return curMax;
    }
};