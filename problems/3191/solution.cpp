class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        
        for (int i = 0; i < size(nums) - 2; i++) {
            if (nums[i] == 0) {
                nums[i] = 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                ans++;
            }
        }
        
        for (const int& b: nums) {
            if (b == 0) {
                return -1;
            }
        }
        
        return ans;
    }
};