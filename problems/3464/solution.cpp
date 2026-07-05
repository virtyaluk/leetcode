class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> vll;
        long long lo = 1,
            hi = side;
        int ans = 0;
        auto check = [&](long long limit) -> bool {
            for (long long start: vll) {
                long long end = start + side *4ll - limit,
                    cur = start;

                for (int i = 0; i < k - 1; i++) {
                    auto it = ranges::lower_bound(vll, cur + limit);

                    if (it == vll.end() or *it > end) {
                        cur = -1;

                        break;
                    }

                    cur = *it;
                }

                if (cur >= 0) {
                    return true;
                }
            }

            return false;
        };

        for (auto& p: points) {
            int x = p.front(),
                y = p.back();
            
            if (not x) {
                vll.push_back(y);
            } else if (y == side) {
                vll.push_back(side + x);
            } else if (x == side) {
                vll.push_back(side * 3ll - y);
            } else {
                vll.push_back(side * 4ll - x);
            }
        }

        sort(begin(vll), end(vll));

        while (lo <= hi) {
            long long mid = (lo + hi) / 2;

            if (check(mid)) {
                lo = mid + 1;
                ans = mid;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};