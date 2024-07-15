class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& k) {
        vector<vector<bool>> b(8, vector<bool>(8));
        vector<vector<int>> ans;
        
        for (const vector<int>& q : queens) {
            b[q[0]][q[1]] = true;
        }
        
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (not i and not j) {
                    continue;
                }
                
                int x = k[0] + i,
                y = k[1] + j;
                
                while (min(x, y) >= 0 and max(x, y) < 8) {
                    if (b[x][y]) {
                        ans.push_back({ x, y });
                        
                        break;
                    }
    
                    x += i;
                    y += j;
                }
            }
        }

        return ans;
    }
};