class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> distinct;
        
        for (int i = 0; i < size(nums); i++) {
            distinct[nums[i]]++;
            
            if (i >= k) {
                distinct[nums[i - k]]--;
                
                if (not distinct[nums[i - k]]) {
                    distinct.erase(nums[i - k]);
                }
            }
            
            if (i >= k - 1) {
                ans.push_back(size(distinct));
            }
        }
        
        return ans;
    }
};