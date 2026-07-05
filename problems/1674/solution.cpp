class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = size(nums),
            ans = n;
        unordered_map<int, int> sumCount;
        vector<int> minArr, maxArr;
        minArr.reserve(n / 2);
        maxArr.reserve(n / 2);

        for (int i = 0; i < n / 2; i++) {
            int a = min(nums[i], nums[n - 1 - i]);
            int b = max(nums[i], nums[n - 1 - i]);

            sumCount[a + b]++;
            minArr.push_back(a);
            maxArr.push_back(b);
        }

        sort(begin(minArr), end(minArr));
        sort(begin(maxArr), end(maxArr));

        for (int c = 2; c <= 2 * limit; c++) {
            int add_left = n / 2 - (lower_bound(begin(minArr), end(minArr), c) - begin(minArr));
            int add_right = lower_bound(begin(maxArr), end(maxArr), c - limit) - begin(maxArr);
            int current_ops = n / 2 + add_left + add_right - sumCount[c];
            ans = min(ans, current_ops);
        }

        return ans;
    }
};