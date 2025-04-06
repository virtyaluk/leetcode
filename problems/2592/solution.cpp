class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int ans = 0;

        sort(begin(nums), end(nums));

        for (const int& num: nums) {
            ans += num > nums[ans];
        }

        return ans;
    }
};