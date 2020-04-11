class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1, n = size(points);
        
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;
            // map<pair<int, int>, int> freq;
            
            for (int j = 1; j < n; j++) {
                int dx = points[j][0] - points[i][0],
                    dy = points[j][1] - points[i][1],
                    g = gcd(dx, dy);
                
                if (g) {
                    dx /= g;
                    dy /= g;
                }
                
                if (dx < 0) {
                    dx *= -1;
                    dy *= -1;
                } else if (not dx) {
                    dy = abs(dy);
                }
                
                ans = max(ans, ++freq[dx * pow(10, 5) + dy] + 1);
                // ans = max(ans, ++freq[{dx, dy}] + 1);
            }
        }
        
        return ans;
    }
};