class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = size(nums);

        for (int i = 0; i < size(nums); i++) {
            if (nums[i] == target) {
                ans = min(ans, abs(i - start));
            }
        }

        return ans;
    }
};