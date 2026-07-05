class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> um;

        for (const int& num: nums) {
            um[num]++;
        }

        for (auto& [num, freq]: um) {
            if (freq % k == 0) {
                ans += num * freq;
            }
        }

        return ans;
    }
};