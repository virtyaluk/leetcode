class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        int mask = (1 << maximumBit) - 1,
            allXor = 0;
        
        for (const int& num: nums) {
            allXor ^= num;
        }
        
        for (int i = 0; i < size(nums); i++) {
            ans.push_back(mask ^ allXor);
            allXor ^= nums[size(nums) - 1 - i];
        }
        
        return ans;
    }
};