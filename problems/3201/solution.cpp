const int patterns[4][2] = {
    {0, 0},
    {0, 1},
    {1, 0},
    {1, 1}
};

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans = 0;

        for (auto& p: patterns) {
            int cnt = 0;

            for (const int& num: nums) {
                cnt += (num % 2 == p[cnt % 2]);
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};