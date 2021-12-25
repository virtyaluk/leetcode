class Solution {
private:
    bool topoSort(vector<unordered_set<int>>& graph, int i, vector<int>& ans, vector<int>& stat) {
        if (stat[i] != 0) {
            return stat[i] == 2;
        }
        
        stat[i] = 1;
        
        for (const int j: graph[i]) {
            if (not topoSort(graph, j, ans, stat)) {
                return false;
            }
        }
        
        stat[i] = 2;
        
        ans.push_back(i);
        
        return true;
    }
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<int> tmp, ans(n), stat(n + 2 * m);
        vector<unordered_set<int>> graph(n + 2 * m);
        
        for (int i = 0; i < n; i++) {
            if (group[i] != -1) {
                graph[n + group[i]].insert(i);
                graph[i].insert(n + m + group[i]);
            }
            
            for (const int& j: beforeItems[i]) {
                if (group[i] != -1 and group[i]  == group[j]) {
                    graph[j].insert(i);
                } else {
                    auto ig = group[i] == -1 ? i : n + group[i];
                    auto jg = group[j] == -1 ? j : n + m + group[j];
                    
                    graph[jg].insert(ig);
                }
            }
        }
        
        for (int n = size(graph) - 1; n >= 0; n--) {
            if (not topoSort(graph, n, tmp, stat)) {
                return {};
            }
        }
        
        reverse(begin(tmp), end(tmp));
        copy_if(begin(tmp), end(tmp), begin(ans), [&](int i) {
            return i < n;
        });
        
        return ans;
    }
};