class Solution {
public:
    int countElements(vector<int>& nums) {
        int ans = 0;
        
        sort(begin(nums), end(nums));
        
        for (int i = 1; i < size(nums) - 1; i++) {
            ans += nums[i] > nums.front() and nums[i] < nums.back();
        }
        
        return ans;
    }
};