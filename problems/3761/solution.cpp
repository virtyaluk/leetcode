class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = size(nums),
            ans = n + 1;
        unordered_map<int, int> um;
        auto reverseNum = [](int x) {
            int y = 0;

            while (x > 0) {
                y = y * 10 + x % 10;
                x /= 10;
            }

            return y;
        };

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            if (um.count(x)) {
                ans = min(ans, i - um[x]);
            }

            um[reverseNum(x)] = i;
        }

        return ans == n + 1 ? -1 : ans;
    }
};