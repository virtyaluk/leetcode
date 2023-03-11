class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        long long int cur, idx = 0, n = size(tasks);
        vector<int> ans;
        vector<vector<int>> t;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        for (int i = 0; i < n; i++) {
            t.push_back({tasks[i][0], tasks[i][1], i});
        }
        
        sort(begin(t), end(t));
        cur = t.front().front();
        
        while (idx < n or not empty(pq)) {
            while (idx < n and t[idx][0] <= cur) {
                pq.push({t[idx][1], t[idx][2]});
                idx++;
            }
            
            auto [procTime, procIdx] = pq.top();
            pq.pop();
            
            cur += procTime;
            ans.push_back(procIdx);
            
            if (idx < n and empty(pq) and cur < t[idx][0]) {
                cur = t[idx][0];
            }
        }
        
        return ans;
    }
};