const int MOD = 1e9 + 7;

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = size(complexity);

        if (*min_element(begin(complexity) + 1, end(complexity)) <= complexity.front()) {
            return 0;
        }

        int ans = 1;

        for (int i = 2; i < n; i++) {
            ans = static_cast<long long>(ans) * i % MOD;
        }

        return ans;
    }
};