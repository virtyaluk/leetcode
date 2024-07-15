class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int, int>>> g(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, INT_MAX);
        unordered_set<int> ans;
        
        for (int i = 0; i < size(meetings); i++) {
            int xi = meetings[i][0],
                yi = meetings[i][1],
                timei = meetings[i][2];
            
            g[xi].push_back({yi, timei});
            g[yi].push_back({xi, timei});
        }
        
        dist[0] = 0;
        dist[firstPerson] = 0;
        pq.push({0, 0});
        ans.insert(0);
        ans.insert(firstPerson);
        
        if (firstPerson != 0) {
            pq.push({0, firstPerson});
        }
        
        while (not empty(pq)) {
            auto [d, u] = pq.top();
            pq.pop();
            
            ans.insert(u);
            
            for (auto [v, vd]: g[u]) {
                if (dist[v] > d and vd >= d and ans.find(v) == end(ans)) {
                    pq.push({vd, v});
                    dist[v] = vd;
                }
            }
        }
        
        return {begin(ans), end(ans)};
    }
};