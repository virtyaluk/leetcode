class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int ans = 0,
            sum = 0,
            n = size(fruits),
            lo = 0,
            hi = 0;
        function<int(int, int)> check = [&](const int& lo, const int& hi) -> int {
            if (fruits[hi].front() <= startPos) {
                return startPos - fruits[lo].front();
            } else if (fruits[lo].front() >= startPos) {
                return fruits[hi].front() - startPos;
            } else {
                return min(
                    abs(startPos - fruits[hi].front()),
                    abs(startPos - fruits[lo].front())
                ) + fruits[hi].front() - fruits[lo].front();
            }
        };

        while (hi < n) {
            sum += fruits[hi].back();

            while (lo <= hi and check(lo, hi) > k) {
                sum -= fruits[lo].back();
                lo++;
            }

            ans = max(ans, sum);
            hi++;
        }

        return ans;
    }
};