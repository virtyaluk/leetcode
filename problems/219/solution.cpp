class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> um;

        for (int i = 0; i < size(nums); i++) {
            if (um.count(nums[i])) {
                if (i - um[nums[i]] <= k) {
                    return true;
                }
            }

            um[nums[i]] = i;
        }

        return false;
    }
};