class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> to;
        unordered_set<int> seen;
        queue<pair<int, int>> q;
        
        for (int i = 0; i < size(routes); i++) {
            for (const int& stop: routes[i]) {
                to[stop].push_back(i);
            }
        }
        
        q.push({source, 0});
        
        while (not empty(q)) {
            auto [stop, buses] = q.front();
            q.pop();
            
            if (stop == target) {
                return buses;
            }
            
            for (const int& bus: to[stop]) {
                for (const int& nextStop: routes[bus]) {
                    if (not seen.count(nextStop)) {
                        seen.insert(nextStop);
                        q.push({nextStop, buses + 1});
                    }
                }
                
                routes[bus].clear();
            }
        }
        
        return -1;
    }
};