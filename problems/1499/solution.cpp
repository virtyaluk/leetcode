// yi + yj + |xi - xj| = yi + xi + yj - xj

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans = INT_MIN;
        deque<pair<int, int>> dq; // xj, yj - xj
        
        for (const vector<int>& point: points) {
            int xj = point[0], yj = point[1], dif = yj - xj;
            
            while (not empty(dq) and xj - dq.front().first > k) {
                dq.pop_front();
            }
            
            if (not empty(dq)) {
                ans = max(ans, yj + xj + dq.front().second);
            }
            
            while (not empty(dq) and (dq.back().second <= dif or xj - dq.back().first > k)) {
                dq.pop_back();
            }
            
            dq.push_back({xj, dif});
        }
        
        return ans;
    }
    
    int findMaxValueOfEquation1(vector<vector<int>>& points, int k) {
        int ans = INT_MIN, n = size(points);
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(points[i][0] - points[j][0]) <= k) {
                    ans = max(ans, points[i][1] + points[j][1] + abs(points[i][0] - points[j][0]));
                }
            }
        }
        
        return ans;
    }
};