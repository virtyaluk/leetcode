class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = size(robots),
            m = size(walls),
            hi = 0,
            lo = 0,
            cur = 0,
            ro = 0,
            prevLo = 0,
            prevHi = 0,
            prevNum = 0,
            subLo = 0,
            subHi = 0;
        vector<pair<int, int>> rd;

        for (int i = 0; i < n; i++) {
            rd.push_back({robots[i], distance[i]});
        }

        sort(begin(rd), end(rd));
        sort(begin(walls), end(walls));

        for (int i = 0; i < n; i++) {
            int roPos = rd[i].first,
                roDistVal = rd[i].second;
            
            while (hi < m and walls[hi] <= roPos) {
                hi++;
            }

            int pos1 = hi;

            while (cur < m and walls[cur] < roPos) {
                cur++;
            }

            int pos2 = cur,
                loBound = (i >= 1) ? max(roPos - roDistVal, rd[i - 1].first + 1) : roPos - roDistVal;
            
            while (lo < m and walls[lo] < loBound) {
                lo++;
            }

            int loPos = lo,
                curLo = pos1 - loPos,
                hiBound = (i < n - 1) ? min(roPos + roDistVal, rd[i + 1].first - 1) : roPos + roDistVal;
            
            while (hi < m and walls[hi] <= hiBound) {
                hi++;
            }

            int hiPos = hi,
                curHi = hiPos - pos2,
                curNum = 0;
            
            if (i > 0) {
                while (ro < m and walls[ro] < rd[i - 1].first) {
                    ro++;
                }

                int pos3 = ro;
                curNum = pos1 - pos3;
            }

            if (i == 0) {
                subLo = curLo;
                subHi = curHi;
            } else {
                int newSubLo = max(subLo + curLo, subHi - prevHi + min(curLo + prevHi, curNum)),
                    newSubHi = max(subLo + curHi, subHi + curHi);
                subLo = newSubLo;
                subHi = newSubHi;
            }

            prevLo = curLo;
            prevHi = curHi;
            prevNum = curNum;
        }

        return max(subLo, subHi);
    }
};