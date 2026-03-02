class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = size(nums),
            len = 1,
            lastLen = 1;
        
        for (int i = 1, curStart = 0, lastEnd = 0; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                len++;
            } else {
                lastLen = len;
                lastEnd = i - 1;
                curStart = i;
                len = 1;
            }

            if ((len == 2 * k) or (len >= k and lastLen >= k and curStart - 1 == lastEnd)) {
                return true;
            }
        }

        return false;
    }
};