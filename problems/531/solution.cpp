class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int ans = 0, m = size(picture), n = size(picture.back());
        vector<int> row(m), col(n);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (picture[i][j] == 'B') {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (picture[i][j] == 'B' and row[i] == 1 and col[j] == 1) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};