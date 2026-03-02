class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = size(nums),
            num1 = 0,
            g = 0,
            minLen = n;
        
        for (const int& num: nums) {
            num1 += num == 1;
            g = gcd(g, num);
        }

        if (num1 > 0) {
            return n - num1;
        }

        if (g > 1) {
            return -1;
        }

        for (int i = 0; i < n; i++) {
            int g = 0;

            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);

                if (g == 1) {
                    minLen = min(minLen, j - i + 1);
                    
                    break;
                }
            }
        }

        return minLen + n - 2;
    }
};