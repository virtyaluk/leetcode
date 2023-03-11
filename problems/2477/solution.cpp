class Solution {
private:
    tuple<long long, long long, long long> dfs(unordered_map<int, unordered_set<int>>& g, int& seats, int u, int parent) {
        long long totalFuel = 0,
            persons = 1;
        
        for (const int& next: g[u]) {
            if (next == parent) {
                continue;
            }
            
            auto [a, b, c] = dfs(g, seats, next, u);
            totalFuel += a + b;
            persons += c;
        }
        
        return {
            totalFuel,
            ceil(persons / float(seats)),
            persons
        };
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        unordered_map<int, unordered_set<int>> g;
        
        for (const vector<int>& e: roads) {
            g[e.front()].insert(e.back());
            g[e.back()].insert(e.front());
        }
        
        return get<0>(dfs(g, seats, 0, -1));
    }
};