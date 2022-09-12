class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans = 0;
        
        for (int i = 0, j = -1, negCount = 0, firstNegIdx = -2; i < size(nums); i++) {
            if (nums[i] == 0) {
                j = i;
                negCount = 0;
                firstNegIdx = -2;
            } else {
                if (nums[i] < 0) {
                    negCount++;
                }
                
                if (negCount == 1 and firstNegIdx == -2) {
                    firstNegIdx = i;
                }
                
                if (negCount % 2 == 0) {
                    ans = max(ans, i - j);
                } else {
                    ans = max(ans, i - firstNegIdx);
                }
            }
        }
        
        return ans;
    }
};