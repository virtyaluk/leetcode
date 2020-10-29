class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int target) {
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
                if (picture[i][j] == 'B' and row[i] == target and col[j] == target) {
                    bool theSame = true;
                    
                    for (int k = 0; k < m; k++) {
                        if (picture[k][j] == 'B' and picture[k] != picture[i]) {
                            theSame = false;
                            break;
                        }
                    }
                    
                    ans += theSame;
                }
            }
        }
        
        return ans;
    }
};