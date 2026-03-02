class Solution {
public:
    int minOperations(string s, int k) {
        int n = size(s),
            m = 0;
        vector<int> dist(n + 1, INT_MAX);
        vector<set<int>> nodeSets(2);
        queue<int> q;

        for (int i = 0; i <= n; i++) {
            nodeSets[i % 2].insert(i);
            
            if (i < n and s[i] == '0') {
                m++;
            }
        }

        q.push(m);
        dist[m] = 0;
        nodeSets[m % 2].erase(m);

        while (not empty(q)) {
            m = q.front();
            q.pop();
            int c1 = max(k - n + m, 0),
                c2 = min(m, k),
                lnode = m + k - 2 * c2,
                rnode = m + k - 2 * c1;
            auto& nodeSet = nodeSets[lnode % 2];

            for (auto iter = nodeSet.lower_bound(lnode); iter != end(nodeSet) && *iter <= rnode;) {
                int m2 = *iter;
                dist[m2] = dist[m] + 1;

                q.push(m2);
                
                iter = next(iter);
                
                nodeSet.erase(m2);
            }
        }

        return dist.front() == INT_MAX ? -1 : dist.front();
    }
};