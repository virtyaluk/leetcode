class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = size(points),
            inf = 1e9 + 7,
            ans = 0;
        unordered_map<float, vector<float>> um1;
        unordered_map<int, vector<float>> um2;

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0],
                y1 = points[i][1];
            
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0],
                    y2 = points[j][1],
                    dx = x1 - x2,
                    dy = y1 - y2;
                float k, b;

                if (x2 == x1) {
                    k = inf;
                    b = x1;
                } else {
                    k = (float) (y2 - y1) / (x2 - x1);
                    b = (float) (y1 * dx - x1 * dy) / dx;
                }

                int mid = (x1 + x2) * 10000 + (y1 + y2);
                um1[k].push_back(b);
                um2[mid].push_back(k);
            }
        }

        for (auto& [_, sti]: um1) {
            if (size(sti) == 1) {
                continue;
            }

            int sum = 0;
            unordered_map<float, int> cnt;

            for (float b: sti) {
                cnt[b]++;
            }

            for (auto& [_, count]: cnt) {
                ans += sum * count;
                sum += count;
            }
        }

        for (auto& [_, mts]: um2) {
            if (size(mts) == 1) {
                continue;
            }

            int sum = 0;
            unordered_map<float, int> cnt;

            for (float k: mts) {
                cnt[k]++;
            }

            for (auto& [_, count]: cnt) {
                ans -= sum * count;
                sum += count;
            }
        }

        return ans;
    }
};