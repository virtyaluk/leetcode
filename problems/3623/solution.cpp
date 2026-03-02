const int MOD = 1e9 + 7;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        long long ans = 0,
            sum = 0;
        unordered_map<int, int> um;

        for (const vector<int>& p: points) {
            um[p.back()]++;
        }

        for (auto &[_, num]: um) {
            long long edge = (long long) num * (num - 1) / 2;
            ans += edge * sum;
            sum += edge;
        }

        return ans % MOD;
    }
};