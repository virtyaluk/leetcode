class Solution {
public:
    vector<long long> getDistances(vector<int>& nums) {
        int n = size(nums);
        vector<long long> ans(n);
        unordered_map<int, vector<int>> um;

        for (int i = 0; i < n; i++) {
            um[nums[i]].push_back(i);
        }

        for (const auto& p: um) {
            const auto& g = p.second;
            long long total = accumulate(begin(g), end(g), 0ll),
                prefTotal = 0;
            
            for (int i = 0; i < size(g); i++) {
                ans[g[i]] = total - prefTotal * 2 + g[i] * (2 * i - size(g));
                prefTotal += g[i];
            }
        }

        return ans;
    }
};