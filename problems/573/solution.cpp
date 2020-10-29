class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int ans = 0, savedDistance = INT_MIN, two;
        
        for (const vector<int>& nut: nuts) {
            ans += 2 * dist(tree, nut);
            
            // one = max(one, dist(nut, tree) - dist(squirrel, nut));
            if (dist(tree, nut) - dist(nut, squirrel) > savedDistance) {
                savedDistance = dist(tree, nut) - dist(nut, squirrel);
                two = -dist(tree, nut) + dist(nut, squirrel);
            }
        }
        
        return ans + two;
    }
    
    int dist(const vector<int>& a, const vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
};