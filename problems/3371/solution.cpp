class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int ans = INT_MIN,
            sum = accumulate(begin(nums), end(nums), 0);
        multiset<int> ms(begin(nums), end(nums));

        for (const int& num: nums) {
            if ((sum - num) % 2 == 0) {
                ms.extract(num);

                int half = (sum - num) / 2;

                if (ms.contains(half)) {
                    ans = max(ans, num);
                }

                ms.insert(num);
            }
        }

        return ans;
    }
};