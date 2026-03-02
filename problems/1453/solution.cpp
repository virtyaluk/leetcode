class Solution {
public:
    int numPoints(vector<vector<int>>& pts, int r) {
        int n = pts.size();
        if (n == 0) return 0;
        int ans = 1;
        const double R = (double)r;
        const double R2 = R * R;
        const double EPS = 1e-7;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                double x1 = pts[i][0], y1 = pts[i][1];
                double x2 = pts[j][0], y2 = pts[j][1];
                double dx = x2 - x1, dy = y2 - y1;
                double d2 = dx*dx + dy*dy;
                double maxd = 2.0 * R;
                if (d2 > maxd*maxd + EPS) continue;
                double d = sqrt(max(0.0, d2));
                if (d < EPS) continue;

                double mx = (x1 + x2) / 2.0;
                double my = (y1 + y2) / 2.0;
                double half = d / 2.0;
                double h = sqrt(max(0.0, R2 - half*half));
                double ux = -dy / d;
                double uy =  dx / d;

                double cx1 = mx + ux * h;
                double cy1 = my + uy * h;
                double cx2 = mx - ux * h;
                double cy2 = my - uy * h;

                int cnt1 = 0, cnt2 = 0;
                for (int k = 0; k < n; ++k) {
                    double px = pts[k][0], py = pts[k][1];
                    double dd1x = px - cx1, dd1y = py - cy1;
                    if (dd1x*dd1x + dd1y*dd1y <= R2 + EPS) ++cnt1;
                    double dd2x = px - cx2, dd2y = py - cy2;
                    if (dd2x*dd2x + dd2y*dd2y <= R2 + EPS) ++cnt2;
                }
                ans = max(ans, max(cnt1, cnt2));
            }
        }

        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            double cx = pts[i][0], cy = pts[i][1];
            for (int k = 0; k < n; ++k) {
                double dx = pts[k][0] - cx, dy = pts[k][1] - cy;
                if (dx*dx + dy*dy <= R2 + EPS) ++cnt;
            }
            ans = max(ans, cnt);
        }

        return ans;
    }
};
