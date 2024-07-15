class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = size(box),
            n = size(box.front());
        vector<vector<char>> ans(n, vector<char>(m, '.'));
        
        for (int i = 0; i < m; i++) {
            int w = n - 1;
            
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == '.') {
                    continue;
                } else if (box[i][j] == '*') {
                    ans[j][m - i - 1] = '*';
                    w = j - 1;
                } else if (box[i][j] == '#') {
                    ans[w--][m - i - 1] = '#';
                }
            }
        }
        
        return ans;
    }
};