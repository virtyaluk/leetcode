class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans = 0, med;
        
        sort(begin(nums), end(nums));
        
        med = nums[nums.size() / 2];
        
        for (const int& num: nums) {
            ans += abs(num - med);
        }
        
        return ans;
    }
};