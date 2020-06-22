class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = size(nums);
        
        for (int i = 0; i < size(nums); i++) {
            ans ^= nums[i];
            ans ^= i;
        }
        
        return ans;
    }
};