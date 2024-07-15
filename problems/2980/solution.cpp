class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        return count_if(begin(nums), end(nums), [](const int& num) {
            return num % 2 == 0;
        }) >= 2;
    }
};