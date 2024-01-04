class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int ans = 0;
        
        for (int i = 1; i < size(nums); i++) {
            for (int j = 0; j < i; j++) {
                ans += (nums[i] + nums[j] < target);
            }
        }
        
        return ans;
    }
};