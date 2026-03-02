class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int ans = 0,
            prev = INT_MIN;
        
        sort(begin(nums), end(nums));

        for (const int& num: nums) {
            int cur = min(max(num - k, prev + 1), num + k);

            if (cur > prev) {
                ans++;
                prev = cur;
            }
        }

        return ans;
    }
};