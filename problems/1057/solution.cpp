typedef tuple<int, int, int> cb;

class Solution {
public:
    int dist(const vector<int>& a, const vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
    
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();
        vector<int> ans(n, -1), bikesUsed(m, -1);
        vector<cb> pairs;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pairs.push_back({dist(workers[i], bikes[j]), i, j});
            }
        }
        
        sort(begin(pairs), end(pairs));
        
        for (auto [ignore, worker, bike]: pairs) {
            if (ans[worker] == -1 && bikesUsed[bike] == -1) {
                ans[worker] = bike;
                bikesUsed[bike] = worker;
            }
        }
        
        return ans;
    }
};