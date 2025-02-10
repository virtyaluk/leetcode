class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int m = INT_MAX,
            cnt = 0;
        
        for (const vector<int>& row: matrix) {
            for (const int& cell: row) {
                ans += abs(cell);
                cnt += cell < 0;
                m = min(m, abs(cell));
            }
        }
        
        if (cnt % 2 == 0) {
            return ans;
        }
        
        return ans - 2 * m;
    }
};