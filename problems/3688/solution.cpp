class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ans = 0;

        for (const int& num: nums) {
            if (num % 2 == 0) {
                ans |= num;
            }
        }

        return ans;
    }
};