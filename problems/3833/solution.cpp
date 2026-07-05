class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int ans = 0;

        for (int i = size(nums) - 2, sumRight = nums.back(), cntRight = 1; i >= 0; i--) {
            ans += nums[i] > (sumRight / cntRight);
            sumRight += nums[i];
            cntRight++;
        }

        return ans;
    }
};