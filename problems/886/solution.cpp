class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, unordered_set<int>> g;
        vector<int> colors(n + 1);
        
        for (const vector<int>& dislike: dislikes) {
            g[dislike[0]].insert(dislike[1]);
            g[dislike[1]].insert(dislike[0]);
        }
        
        for (int i = 1; i <= n; i++) {
            if (colors[i] != 0) {
                continue;
            }
            
            queue<int> q;
            
            colors[i] = 1;
            q.push(i);
            
            while (not empty(q)) {
                int node = q.front();
                q.pop();
                
                for (const int& next: g[node]) {
                    if (colors[next] != 0) {
                        if (colors[next] == colors[node]) {
                            return false;
                        }
                    } else {
                        q.push(next);
                        colors[next] -= colors[node];
                    }
                }
            }
        }
        
        return true;
    }
};