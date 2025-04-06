class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0,
            n = size(colors);

        for (int i = 1, prev = colors.front(), cur = 1; i < n + k - 1; i++) {
            int idx = i % n;

            if (colors[idx] == prev) {
                cur = 1;
                prev = colors[idx];
                continue;
            }

            ans += ++cur >= k;
            prev = colors[idx];
        }

        return ans;
    }
};