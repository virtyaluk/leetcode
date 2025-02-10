class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;

        for (int i = 1, incr = 1, decr = 1; i < size(nums); i++) {
            if (nums[i] > nums[i - 1]) {
                incr++;
            } else {
                incr = 1;
            }
            
            ans = max(ans, incr);

            if (nums[i] < nums[i - 1]) {
                decr++;
            } else {
                decr = 1;
            }

            ans = max(ans, decr);
        }

        return ans;
    }
};