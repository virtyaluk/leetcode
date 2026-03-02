class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = size(nums);
        long long ans = LLONG_MAX,
            chosenSum = 0;
        multiset<int> chosen,
            unused;

        for (int j = 2; j <= min(1 + dist, n - 1); j++) {
            unused.insert(nums[j]);
        }

        for (int cnt = 0; cnt < k - 2 and not empty(unused); cnt++) {
            auto it = begin(unused);
            chosen.insert(*it);
            chosenSum += *it;
            unused.erase(it);
        }

        for (int i1 = 1; i1 < n; i1++) {
            if ((int) size(chosen) == k - 2) {
                ans = min(ans, (long long)nums[0] + nums[i1] + chosenSum);
            }

            if (i1 + 1 < n) {
                int out = nums[i1 + 1];
                auto itChosen = chosen.find(out);

                if (itChosen != end(chosen)) {
                    chosenSum -= out;
                    chosen.erase(itChosen);
                } else {
                    auto itUnused = unused.find(out);
                    if (itUnused != end(unused)) {
                        unused.erase(itUnused);
                    }
                }
            }

            if (i1 + dist + 1 < n) {
                unused.insert(nums[i1 + dist + 1]);
            }

            while ((int) size(chosen) < k - 2 and not empty(unused)) {
                auto it = begin(unused);
                chosen.insert(*it);
                chosenSum += *it;
                unused.erase(it);
            }

            while (not empty(chosen) and not empty(unused) and *chosen.rbegin() > *unused.begin()) {
                int big = *chosen.rbegin();
                int small = *unused.begin();
    
                chosen.erase(prev(end(chosen)));
                unused.erase(begin(unused));
                chosen.insert(small);
                unused.insert(big);

                chosenSum += small - big;
            }
        }

        return ans;
    }
};