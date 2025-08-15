class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans = -1;
        unordered_map<int, vector<int>> um;

        for (const int& num: nums) {
            int n = num,
                maxDigit = 0;
            
            while (n) {
                maxDigit = max(maxDigit, n % 10);
                n /= 10;
            }

            um[maxDigit].push_back(num);
        }

        for (auto [_, n]: um) {
            if (size(n) < 2) {
                continue;
            }

            sort(begin(n), end(n), greater());

            ans = max(ans, n[0] + n[1]);
        }

        return ans;
    }
};