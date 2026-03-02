class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int ans = 0;
        vector<int> maxRow(n + 1),
            minRow(n + 1, n + 1),
            maxCol(n + 1),
            minCol(n + 1, n + 1);
        
        for (const vector<int>& b: buildings) {
            int x = b.front(),
                y = b.back();
            maxRow[y] = max(maxRow[y], x);
            minRow[y] = min(minRow[y], x);
            maxCol[x] = max(maxCol[x], y);
            minCol[x] = min(minCol[x], y);
        }

        for (const vector<int>& b: buildings) {
            int x = b.front(),
                y = b.back();
            ans += x > minRow[y] and x < maxRow[y] and y > minCol[x] and y < maxCol[x];
        }

        return ans;
    }
};