class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        
        sort(begin(nums), end(nums));
        
        for (const int& num: nums) {
            if (empty(ans) or size(ans.back()) == 3) {
                ans.push_back({num});
            } else if (abs(ans.back().front() - num) <= k) {
                ans.back().push_back(num);
            } else {
                return {};
            }
        }
        
        if (not empty(ans) and size(ans.back()) != 3) {
            return {};
        }
        
        return ans;
    }
};