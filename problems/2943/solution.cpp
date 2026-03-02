class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(begin(hBars), end(hBars));
        sort(begin(vBars), end(vBars));
        
        int hMax = 1,
            vMax = 1,
            hCur = 1,
            vCur = 1;
        
        for (int i = 1; i < size(hBars); i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                hCur++;
            } else {
                hCur = 1;
            }

            hMax = max(hMax, hCur);
        }

        for (int i = 1; i < size(vBars); i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                vCur++;
            } else {
                vCur = 1;
            }

            vMax = max(vMax, vCur);
        }

        int side = min(hMax, vMax) + 1;

        return side * side;
    }
};