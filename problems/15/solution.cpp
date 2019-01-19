class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (size(nums) < 3) {
            return {};
        }
        
        int n = size(nums);
        vector<vector<int>> ans;
        
        sort(begin(nums), end(nums));
        
        for (int i = 0; i < n - 2; i++) {
            if (i and nums[i] == nums[i - 1]) {
                continue;
            }
            
            int j = i + 1, k = n - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    
                    while (j < k and nums[j] == nums[j + 1]) {
                        j++;
                    }
                    
                    while (j < k and nums[k] == nums[k - 1]) {
                        k--;
                    }
                    
                    j++;
                    k--;
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        
        return ans;
    }
};