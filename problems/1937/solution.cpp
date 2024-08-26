class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        long long ans = 0,
            rm = 0;
        int m = size(points.front());
        vector<long long> curRow(m),
            prevRow(m);
        
        for (const vector<int>& row: points) {
            rm = 0;
            
            for (int i = 0; i < m; i++) {
                rm = max(rm - 1, prevRow[i]);
                curRow[i] = rm;
            }
            
            rm = 0;
            
            for (int i = m - 1; i >= 0; i--) {
                rm = max(rm - 1, prevRow[i]);
                curRow[i] = max(curRow[i], rm) + row[i];
            }
            
            prevRow = curRow;
        }
        
        for (int i = 0; i < m; i++) {
            ans = max(ans, prevRow[i]);
        }
        
        return ans;
    }
};