class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(helper(nums, firstLen, secondLen), helper(nums, secondLen, firstLen));
    }
    
    int helper(vector<int>& nums, int firstLen, int secondLen) {
        int ans = 0, sumFirst = 0, sumSecond = 0, maxSumFirst = 0;
        
        for (int i = 0; i < size(nums); i++) {
            sumSecond += nums[i];
            
            if (i >= secondLen) {
                sumSecond -= nums[i - secondLen];
                sumFirst += nums[i - secondLen];
            }
            
            if (i >= firstLen + secondLen) {
                sumFirst -= nums[i - firstLen - secondLen];
            }
            
            maxSumFirst = max(maxSumFirst, sumFirst);
            ans = max(ans, maxSumFirst + sumSecond);
        }
        
        return ans;
    }
};