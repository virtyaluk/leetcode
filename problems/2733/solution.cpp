class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int m = *min_element(begin(nums), end(nums)),
            M = *max_element(begin(nums), end(nums));
        
        for (const int& num: nums) {
            if (num != m and num != M) {
                return num;
            }
        }
        
        return -1;
    }
};