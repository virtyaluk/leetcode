class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        vector<vector<int>> ans;
        vector<int> cycle;
        unordered_map<int, deque<int>> g;
        unordered_map<int, int> indeg, outdeg;
        stack<int> st;
        int startNode = -1;
        
        for (const vector<int>& p: pairs) {
            g[p.front()].push_back(p.back());
            outdeg[p.front()]++;
            indeg[p.back()]++;
        }
        
        for (auto& [node, _]: outdeg) {
            if (outdeg[node] == indeg[node] + 1) {
                startNode = node;
                
                break;
            }
        }
        
        if (startNode == -1) {
            startNode = pairs.front().front();
        }
        
        st.push(startNode);
        
        while (not empty(st)) {
            int node = st.top();
            
            if (not empty(g[node])) {
                int next = g[node].front();
                
                g[node].pop_front();
                st.push(next);
            } else {
                cycle.push_back(node);
                st.pop();
            }
        }
        
        reverse(begin(cycle), end(cycle));
        
        for (int i = 1; i < size(cycle); i++) {
            ans.push_back({cycle[i - 1], cycle[i]});
        }
        
        return ans;
    }
};