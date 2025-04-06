class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        unordered_map<int, vector<int>> um;

        for (const int& num: nums) {
            int x = num,
                sum = 0;
            
            while (x) {
                sum += x % 10;
                x /= 10;
            }

            um[sum].push_back(num);
        }

        for (auto& [_, nums2]: um) {
            if (size(nums2) < 2) {
                continue;
            }

            sort(begin(nums2), end(nums2), greater<>());

            ans = max(ans, nums2.front() + nums2[1]);
        }

        return ans;
    }
};