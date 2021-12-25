class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size(), k = arr[0].size();
        
        for (int i = 1; i < n; i++) {
            int firstMin = INT_MAX, secondMin = INT_MAX, firstMinIdx = -1;
            
            for (int j = 0; j < k; j++) {
                if (firstMin > arr[i - 1][j]) {
                    firstMin = arr[i - 1][j];
                    firstMinIdx = j;
                }
            }
            
            for (int j = 0; j < k; j++) {
                if (j != firstMinIdx) {
                    secondMin = min(secondMin, arr[i - 1][j]);
                }
            }
            
            for (int j = 0; j < k; j++) {
                if (j == firstMinIdx) {
                    arr[i][j] += secondMin;
                } else {
                    arr[i][j] += firstMin;
                }
            }
            
//             for (int j = 0; j < k; j++) {
//                 int minSoFar = INT_MAX;
                
//                 for (int c = 0; c < k; c++) {
//                     if (c != j) {
//                         minSoFar = min(minSoFar, arr[i - 1][c]);
//                     }
//                 }
                
//                 arr[i][j] += minSoFar;
//             }
        }
        
        return *min_element(begin(arr[n - 1]), end(arr[n - 1]));
    }
};