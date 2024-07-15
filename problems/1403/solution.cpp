class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> ans;
        int sum = accumulate(begin(nums), end(nums), 0);
        
        sort(begin(nums), end(nums), greater<>());
        
        for (int i = 0, cur = 0; i < size(nums); i++) {
            sum -= nums[i];
            cur += nums[i];
            ans.push_back(nums[i]);
            
            if (cur > sum) {
                break;
            }
        }
        
        return ans;
    }
};