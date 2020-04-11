class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (not matrix.size()) {
            return 0;
        }
        
        int m = matrix.size(), n = matrix.back().size(), ans = 0;
        vector<int> height(n), left(n), right(n, n);
        
        for (int i = 0; i < m; i++) {
            int leftEdge = 0, rightEdge = n;
            
            for (int j = 0; j < n; j++) {
                height[j] = matrix[i][j] == '1' ? 1 + height[j] : 0;
            }
            
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], leftEdge);
                } else {
                    left[j] = 0;
                    leftEdge = j + 1;
                }
            }
            
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], rightEdge);
                } else {
                    right[j] = n;
                    rightEdge = j;
                }
            }
            
            for (int j = 0; j < n; j++) {
                ans = max(ans, height[j] * (right[j] - left[j]));
            }
            
            // copy(begin(height), end(height), ostream_iterator<int>(cout, " ")); cout << endl;
            // copy(begin(left), end(left), ostream_iterator<int>(cout, " ")); cout << endl;
            // copy(begin(right), end(right), ostream_iterator<int>(cout, " ")); cout << endl;
            // cout << endl;
        }
        
        return ans;
    }
};