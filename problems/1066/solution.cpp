typedef tuple<int, int, int> wb;

class Solution {
public:
    int dist(const vector<int>& a, const vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
    
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int m = workers.size(), n = bikes.size();
        priority_queue<wb, vector<wb>, greater<wb>> q;
        set<pair<int, int>> visited;
        
        q.push({0, 0, 0});
        
        while (!q.empty()) {
            auto [curDist, worker, taken] = q.top();
            q.pop();
            
            if (visited.count({worker, taken})) {
                continue;
            }
            
            visited.insert({worker, taken});
            
            if (worker == m) {
                return curDist;
            }
            
            for (int bike = 0; bike < n; bike++) {
                if ((taken & (1 << bike)) == 0) {
                    q.push({
                        curDist + dist(workers[worker], bikes[bike]),
                        worker + 1,
                        taken | (1 << bike)
                    });
                }
            }
        }
        
        return 0;
    }
};