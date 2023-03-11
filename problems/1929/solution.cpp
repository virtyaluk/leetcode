class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        nums.insert(end(nums), begin(nums), end(nums));
        
        return nums;
    }
};