class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < size(nums) - 1; i++) {
            int x = to_string(nums[i]).front() - '0';

            for (int j = i + 1; j < size(nums); j++) {
                int y = nums[j] % 10;
                ans += gcd(x, y) == 1;
            }
        }

        return ans;
    }
};