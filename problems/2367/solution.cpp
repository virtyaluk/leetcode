class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans = 0, n = size(nums);
        
        for (int i = 1; i < n - 1; i++) {
            if (binary_search(begin(nums), begin(nums) + i, nums[i] - diff) and binary_search(begin(nums) + i + 1, end(nums), nums[i] + diff)) {
                ans++;
            }
        }
        
        return ans;
    }
};