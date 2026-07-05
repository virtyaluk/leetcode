class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans = 0;
        unordered_map<long long, int> um;

        for (const int& num: nums) {
            um[num]++;
        }

        ans = um[1] - (um[1] % 2 == 0 ? 1 : 0);

        um.erase(1);

        for (auto& [num, _]: um) {
            int res = 0;
            long long x = num;

            for (; um.contains(x) and um[x] > 1; x *= x) {
                res += 2;
            }

            ans = max(ans, res + (um.contains(x) ? 1 : -1));
        }

        return ans;
    }
};