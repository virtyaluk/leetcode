class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int m = INT_MAX;
        unordered_map<int, int> freq;
        vector<int> merge;

        for (const int& num: basket1) {
            freq[num]++;
            m = min(m, num);
        }

        for (const int& num: basket2) {
            freq[num]--;
            m = min(m, num);
        }

        for (auto [num, cnt]: freq) {
            if (cnt % 2 != 0) {
                return -1;
            }

            for (int i = 0; i < abs(cnt) / 2; i++) {
                merge.push_back(num);
            }
        }

        nth_element(begin(merge), begin(merge) + size(merge) / 2, end(merge));

        return accumulate(begin(merge), begin(merge) + size(merge) / 2, 0ll, [&](long long ans, int x) -> long long {
            return ans + min(2 * m, x);
        });
    }
};