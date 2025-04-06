class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int ans = 0,
            cur = 0,
            last = days;
        map<int, int> line;

        for (const vector<int>& m: meetings) {
            last = min(last, m.front());
            line[m.front()]++;
            line[m.back() + 1]--;
        }

        ans += last - 1;

        for (auto [day, m]: line) {
            if (not cur) {
                ans += day - last;
            }

            cur += m;
            last = day;
        }

        ans += days - last + 1;

        return ans;
    }
};