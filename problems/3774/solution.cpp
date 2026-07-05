class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int smallest = 0,
            largest = 0,
            n = size(nums);

        sort(begin(nums), end(nums));
            
        for (int i = 0; i < k; i++) {
            smallest += nums[i];
            largest += nums[n - i - 1];
        }

        return abs(largest - smallest);
    }
};