class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> g;
        vector<int> oddNodes;

        for (const vector<int>& e: edges) {
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }

        for (int i = 1; i <= n; i++) {
            if (size(g[i]) % 2 == 1) {
                oddNodes.push_back(i);
            }
        }

        if (size(oddNodes) == 0) {
            return true;
        }

        if (size(oddNodes) == 2) {
            int a = oddNodes[0],
                b = oddNodes[1];
            
            if (not g[a].count(b)) {
                return true;
            }

            for (int c = 1; c <= n; c++) {
                if (c != a and c != b and not g[a].count(c) and not g[b].count(c)) {
                    return true;
                }
            }

            return false;
        }

        if (size(oddNodes) == 4) {
            int a = oddNodes[0],
                b = oddNodes[1],
                c = oddNodes[2],
                d = oddNodes[3];
            
            return (not g[a].count(b) and not g[c].count(d)) or
                (not g[a].count(c) and not g[b].count(d)) or
                (not g[a].count(d) and not g[b].count(c));
        }

        return false;
    }
};