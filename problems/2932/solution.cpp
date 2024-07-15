class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int ans = 0;
        
        for (const int& num1: nums) {
            for (const int& num2: nums) {
                if (abs(num1 - num2) <= min(num1, num2)) {
                    ans = max(ans, num1 ^ num2);
                }
            }
        }
        
        return ans;
    }
};