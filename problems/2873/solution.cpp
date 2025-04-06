class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;

        for (int i = 0; i < size(nums) - 2; i++) {
            for (int j = i + 1; j < size(nums) - 1; j++) {
                for (int k = j + 1; k < size(nums); k++) {
                    long long cur = ((long long) nums[i] - (long long) nums[j]) * (long long) nums[k];
                    ans = max(ans, cur);
                }
            }
        }

        return ans < 0 ? 0 : ans;
    }
};