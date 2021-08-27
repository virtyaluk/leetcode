class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int ans = 0, i = 0;
        priority_queue<int> pq;
        
        while (startFuel < target) {
            while (i < size(stations) and stations[i][0] <= startFuel) {
                pq.push(stations[i++][1]);
            }
            
            if (pq.empty()) {
                return -1;
            }
            
            startFuel += pq.top();
            pq.pop();
            ans++;
        }
        
        return ans;
    }
    
    int minRefuelStops1(int target, int startFuel, vector<vector<int>>& stations) {
        int ans = 0;
        priority_queue<int> pq;
        
        for (int i = 0; startFuel < target; ans++) {
            while (i < size(stations) and stations[i][0] <= startFuel) {
                pq.push(stations[i++][1]);
            }
            
            if (pq.empty()) {
                return -1;
            }
            
            startFuel += pq.top();
            pq.pop();
        }
        
        return ans;
    }
};