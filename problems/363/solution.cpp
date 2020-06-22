class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int ans = INT_MIN, rows = size(matrix), cols = size(matrix.back());
        
        for (int colLeft = 0; colLeft < cols; colLeft++) {
            vector<int> rowSum(rows);
            
            for (int colRight = colLeft; colRight < cols; colRight++) {
                for (int row = 0; row < rows; row++) {
                    rowSum[row] += matrix[row][colRight];
                }

                set<int> runSum = {0};
                int curSum = 0, curMax = INT_MIN;

                for (const int& sum: rowSum) {
                    curSum += sum;

                    auto it = runSum.lower_bound(curSum - k);

                    if (it != end(runSum)) {
                        curMax = max(curMax, curSum - *it);
                    }

                    runSum.insert(curSum);
                }

                ans = max(ans, curMax);
            }
        }
        
        return ans;
    }
};