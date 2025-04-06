class Solution {
public:
    int visibleMountains(vector<vector<int>>& peaks) {
        int ans = 0,
            n = size(peaks);

        sort(begin(peaks), end(peaks), [](const vector<int>& a, const vector<int>& b) {
            int ya = a[1] - a[0],
                yb = b[1] - b[0];

                if (ya != yb) {
                    return ya > yb;
                }

                int xa = a[0] + a[1],
                    xb = b[0] + b[1];
                
                return xa > xb;
        });

        for (int i = 0, m = 0; i < n; i++) {
            int x = peaks[i][0] + peaks[i][1];

            if (x > m) {
                if (i + 1 == n or peaks[i][0] != peaks[i + 1][0] or peaks[i][1] != peaks[i + 1][1]) {
                    ans++;
                }

                m = x;
            }
        }

        return ans;
    }
};