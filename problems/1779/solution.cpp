class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = -1;
        auto md = [&](const vector<int>& p) {
            return abs(x - p[0]) + abs(y - p[1]);
        };
        
        for (int i = 0; i < size(points); i++) {
            if (points[i][0] == x or points[i][1] == y) {
                if (ans == -1 or md(points[ans]) > md(points[i])) {
                    ans = i;
                }
            }
        }
        
        return ans;
    }
};