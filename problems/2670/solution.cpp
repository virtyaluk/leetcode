class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = size(nums);
        vector<int> ans(n);
        unordered_set<int> us;
        
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = size(us);
            us.insert(nums[i]);
        }
        
        us.clear();
        
        for (int i = 0; i < n; i++) {
            us.insert(nums[i]);
            ans[i] = size(us) - ans[i];
        }
        
        return ans;
    }
};