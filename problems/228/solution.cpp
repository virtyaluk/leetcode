class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
    
        for (int i = 0; i < size(nums);) {
            int j = i;
            
            while (j + 1 < size(nums) and nums[j + 1] - 1 == nums[j]) {
                j++;
            }
            
            if (nums[i] == nums[j]) {
                ans.push_back(to_string(nums[i]));
            } else {
                ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            }
            
            i = j + 1;
        }
        
        return ans;
    }
};