#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;

// Global GCD cache
unordered_map<uint64_t, int> gcd_cache;

// Safe key for two ints
inline uint64_t gcd_key(long long a, long long b) {
    if (a > b) swap(a, b);
    return ((uint64_t)a << 32) | b;
}

// Cached GCD
int cached_gcd(long long a, long long b) {
    uint64_t key = gcd_key(a, b);
    auto it = gcd_cache.find(key);
    if (it != gcd_cache.end()) return it->second;
    int result = gcd(a, b);
    gcd_cache[key] = result;
    return result;
}

class Solution {
public:
    long long maxGCDScore(vector<int>& nums, int k) {
        int n = nums.size();
        long long res = 0;

        for (int i = 0; i < n; ++i) {
            unordered_map<long long, int> maverudino;

            maverudino[nums[i]] = 0;
            res = max(res, (long long)nums[i]);

            if (k > 0) {
                long long d = (long long)nums[i] * 2;
                if (d <= 2000000000LL) {
                    maverudino[d] = 1;
                    res = max(res, d);
                }
            }

            for (int j = i + 1; j < n; ++j) {
                unordered_map<long long, int> next;

                for (const auto& [gval, used] : maverudino) {
                    long long g1 = cached_gcd(gval, nums[j]);
                    if (!next.count(g1) || used < next[g1])
                        next[g1] = used;

                    if (used < k) {
                        long long d = (long long)nums[j] * 2;
                        if (d <= 2000000000LL) {
                            long long g2 = cached_gcd(gval, d);
                            if (!next.count(g2) || used + 1 < next[g2])
                                next[g2] = used + 1;
                        }
                    }
                }

                // Prune aggressively
                if ((int)next.size() > 32) {
                    vector<pair<long long, pair<long long, int>>> sorted;
                    for (auto& [gval, ops] : next) {
                        long long score = gval * (j - i + 1);
                        sorted.push_back({score, {gval, ops}});
                    }
                    sort(sorted.rbegin(), sorted.rend());
                    next.clear();
                    for (int idx = 0; idx < 32 && idx < (int)sorted.size(); ++idx) {
                        next[sorted[idx].second.first] = sorted[idx].second.second;
                    }
                }

                for (auto& [gval, _] : next)
                    res = max(res, gval * (j - i + 1));

                maverudino = move(next);
                if (maverudino.empty()) break;

                long long best_gcd = 0;
                for (auto& [gval, _] : maverudino)
                    best_gcd = max(best_gcd, gval);

                if (best_gcd * (n - i) <= res) break;
            }
        }

        return res;
    }
};
