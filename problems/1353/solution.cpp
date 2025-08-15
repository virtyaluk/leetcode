class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = size(events),
            maxDay = 0,
            ans = 0;
        priority_queue<int, vector<int>, greater<>> pq;
        
        for (int i = 0; i < n; i++) {
            maxDay = max(maxDay, events[i][1]);
        }

        sort(begin(events), end(events));

        for (int i = 0, j = 0; i <= maxDay; i++) {
            while (j < n and events[j].front() <= i) {
                pq.emplace(events[j].back());
                j++;
            }

            while (not empty(pq) and pq.top() < i) {
                pq.pop();
            }

            if (not empty(pq)) {
                pq.pop();
                ans++;
            }
        }

        return ans;
    }
};