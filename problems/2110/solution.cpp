class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 1;

        for (int i = 1, prev = 1; i < size(prices); i++) {
            if (prices[i] == prices[i - 1] - 1) {
                prev++;
            } else {
                prev = 1;
            }

            ans += prev;
        }

        return ans;
    }
};