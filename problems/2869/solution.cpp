class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        bitset<64> bs((1ll << k) - 1);

        for (int i = size(nums) - 1; i >= 0 and bs.to_ulong() != 0ll; i--) {
            bs[nums[i] - 1] = false;
            ans++;
        }

        return ans;
    }
};