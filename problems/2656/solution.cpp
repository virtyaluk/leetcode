class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int m = *max_element(begin(nums), end(nums));
        
        return m * k + k * (k - 1) / 2;
    }
};