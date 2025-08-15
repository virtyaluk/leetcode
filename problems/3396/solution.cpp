class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        bitset<128> bs;
        
        for (int i = size(nums) - 1; i >= 0; i--) {
            if (bs[nums[i]]) {
                return i / 3 + 1;
            }

            bs[nums[i]] = true;
        }

        return ans;
    }
};