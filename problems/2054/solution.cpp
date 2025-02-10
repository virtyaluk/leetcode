class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int ans = 0,
            maxVal = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        sort(begin(events), end(events));
        
        for (const vector<int>& e: events) {
            while (not empty(pq) and pq.top().first < e.front()) {
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
            }
            
            ans = max(ans, e.back() + maxVal);
            pq.push({e[1], e.back()});
        }
        
        return ans;
    }
};