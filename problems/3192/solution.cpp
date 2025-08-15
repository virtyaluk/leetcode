class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;

        for (const int& num: nums) {
            ans += (not num and ans % 2 == 0) or (num == 1 and ans % 2 == 1);
        }

        return ans;
    }
};