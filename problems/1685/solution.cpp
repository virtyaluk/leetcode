class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size(), s = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ans(n), left(n), right(n);
        
        for (int i = 0, acc = 0; i < nums.size(); i++) {
            left[i] = acc;
            acc += abs(nums[i]);
        }
        
        for (int i = n - 1, acc = 0; i >= 0; i--) {
            right[i] = acc;
            acc += abs(nums[i]);
        }
        
        for (int i = 0; i < nums.size(); i++) {
            ans[i] += abs(nums[i] * i - left[i]);
            ans[i] += abs(nums[i] * (n - i - 1) - right[i]);
        }
        
        return ans;
    }
};