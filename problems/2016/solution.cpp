class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minPrice = INT_MAX,
            maxProfit = 0;
        
        for (int i = 0; i < size(nums); i++) {
            minPrice = min(minPrice, nums[i]);
            maxProfit = max(maxProfit, nums[i] - minPrice);
        }
        
        if (not maxProfit) {
            return -1;
        }
        
        return maxProfit;
    }
};