class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        
        sort(begin(nums), end(nums));
        
        for (int i = 1; i < size(nums); i++) {
            nums[i] += nums[i - 1];
        }
        
        for (const int& sum: queries) {
            auto it = upper_bound(begin(nums), end(nums), sum);
            
            ans.push_back(distance(begin(nums), it));
        }
        
        return ans;
    }
};