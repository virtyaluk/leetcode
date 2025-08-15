class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int ans = 0,
            maxCount = 0;
        unordered_map<int, int> um;

        for (int i = 1; i < size(nums); i++) {
            if (nums[i - 1] == key) {
                um[nums[i]]++;

                if (um[nums[i]] > maxCount) {
                    maxCount = um[nums[i]];
                    ans = nums[i];
                }
            }
        }

        return ans;
    }
};