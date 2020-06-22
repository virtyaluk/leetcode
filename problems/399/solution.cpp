class Solution {
private:
    unordered_map<string, unordered_map<string, double>> g;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans(queries.size());
        
        for (int i = 0; i < equations.size(); i++) {
            vector<string> eq = equations[i];
            string divident = eq[0], divisor = eq[1];
            double quotient = values[i];
            
            g[divident][divisor] = quotient;
            g[divisor][divident] = 1 / quotient;
        }
        
        for (int i = 0; i < queries.size(); i++) {
            vector<string> query = queries[i];
            string divident = query[0], divisor = query[1];
            
            if (g.find(divident) == g.end() || g.find(divisor) == g.end()) {
                ans[i] = -1.0;
            } else if (divident == divisor) {
                ans[i] = 1.0;
            } else {
                set<string> visited;
                
                ans[i] = dfs(divident, divisor, 1.0, visited);
            }
        }
        
        return ans;
    }
    
    double dfs(string cur, string target, double prod, set<string> visited) {
        visited.insert(cur);
        
        double ans = -1.0;
        unordered_map<string, double> neighbors = g[cur];
        
        if (neighbors.find(target) != neighbors.end()) {
            ans = prod * neighbors[target];
        } else {
            for (auto [neighbor, value]: neighbors) {
                if (visited.find(neighbor) != visited.end()) {
                    continue;
                }
                
                ans = dfs(neighbor, target, prod * value, visited);
                
                if (ans != -1.0) {
                    break;
                }
            }
        }
        
        visited.erase(cur);

        return ans;
    }
};