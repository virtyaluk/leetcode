class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<tuple<int, int, int>> jobs;
        
        for (int i = 0; i < size(startTime); i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(begin(jobs), end(jobs));
        
        return helper(jobs);
    }
    
    int helper(vector<tuple<int, int, int>>& jobs) {
        int maxProfit = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        for (auto &[start, end, profit]: jobs) {
            while (not empty(pq) and pq.top().first <= start) {
                maxProfit = max(maxProfit, pq.top().second);
                pq.pop();
            }
            
            pq.push({end, profit + maxProfit});
        }
        
        while (not empty(pq)) {
            maxProfit = max(maxProfit, pq.top().second);
            pq.pop();
        }
        
        return maxProfit;
    }
};