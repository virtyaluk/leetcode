class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int ans = 0,
            cur = 0,
            prev = 0;

        for (auto e: events) {
            if (e[1] - prev > cur or (e[1] - prev == cur and e[0] < ans)) {
                cur = e[1] - prev;
                ans = e[0];
            }

            prev = e[1];
        }

        return ans;
    }
};