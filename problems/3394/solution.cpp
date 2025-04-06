class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int h = 0,
            v = 0;
        vector<pair<int, int>> hline, vline;

        for (const vector<int>& r: rectangles) {
            int startx = r[0],
                starty = r[1],
                endx = r[2],
                endy = r[3];
            
            hline.push_back({startx, endx});
            vline.push_back({starty, endy});
        }

        sort(begin(hline), end(hline));
        sort(begin(vline), end(vline));

        for (int i = 1, m = hline.front().second; i < size(hline); i++) {
            if (m <= hline[i].first) {
                h++;
                m = hline[i].second;
            } else {
                m = max(m, hline[i].second);
            }
        }

        if (h >= 2) {
            return true;
        }

        for (int i = 1, m = vline.front().second; i < size(vline); i++) {
            if (m <= vline[i].first) {
                v++;
                m = vline[i].second;
            } else {
                m = max(m, vline[i].second);
            }
        }

        return v >= 2;
    }
};