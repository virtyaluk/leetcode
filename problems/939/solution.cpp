class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int ans = INT_MAX;
        unordered_map<int, unordered_map<int, bool>> seen;
        
        for (const vector<int>& p1: points) {
            int x1 = p1[0], y1 = p1[1];
            
            for (const vector<int>& p2: points) {
                int x2 = p2[0], y2 = p2[1];
                
                if (seen[x1][y2] and seen[x2][y1]) {
                    ans = min(ans, abs(x1 - x2) * abs(y1 - y2));
                }
            }
            
            seen[x1][y1] = true;
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};