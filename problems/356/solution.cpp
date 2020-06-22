class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        unordered_map<int, set<int>> m;
        float mid = 0.0;
        
        for (vector<int> point: points) {
            m[point[0]].insert(point[1]);
        }
        
        for (auto [x, _]: m) {
            mid += x;
        }
        
        mid /= m.size();
        
        for (auto [x, _]: m) {
            if (x < mid && m[x] != m[2 * mid - x]) {
                return false;
            }
        }
        
        return true;
    }
};