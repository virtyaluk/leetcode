class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double ans = numeric_limits<double>::max(),
            cur = 0.0;
        vector<pair<double, int>> qw;
        priority_queue<int> pq;
        
        for (int i = 0; i < size(wage); i++) {
            qw.push_back({
                ((double) wage[i]) / ((double) quality[i]),
                quality[i]
            });
        }
        
        sort(begin(qw), end(qw));
        
        for (int i = 0; i < size(wage); i++) {
            pq.push(qw[i].second);
            cur += qw[i].second;
            
            if (size(pq) > k) {
                cur -= pq.top();
                pq.pop();
            }
            
            if (size(pq) == k) {
                ans = min(ans, cur * qw[i].first);
            }
        }
        
        return ans;
    }
};