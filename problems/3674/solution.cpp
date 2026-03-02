class Solution {
public:
    int minOperations(vector<int>& nums) {
        for (const int& num: nums) {
            if (num != nums.front()) {
                return 1;
            }
        }

        return 0;
    }
};