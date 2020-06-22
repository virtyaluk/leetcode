class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> ans;
        unordered_map<string, multiset<string>> g;
        
        for (const vector<string>& t: tickets) {
            g[t[0]].insert(t[1]);
        }
        
        dfs(g, "JFK", ans);

        reverse(begin(ans), end(ans));
        
        return ans;
    }
    
    void dfs(unordered_map<string, multiset<string>>& g, string city, vector<string>& ans) {
        while (not empty(g[city])) {
            string next = *begin(g[city]);
            g[city].erase(begin(g[city]));
            dfs(g, next, ans);
        }
        
        ans.push_back(city);
    }
};