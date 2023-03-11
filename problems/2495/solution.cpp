class Solution {
public:
    long long evenProduct(vector<int>& nums) {
        long long int ans = 0;
        int lastEvenIdx = -1;
        
        for (int i = 0; i < size(nums); i++) {
            if (nums[i] % 2 == 0) {
                ans += i + 1;
                lastEvenIdx = i;
            } else if (lastEvenIdx != -1) {
                ans += lastEvenIdx + 1;
            }
        }
        
        return ans;
    }
};