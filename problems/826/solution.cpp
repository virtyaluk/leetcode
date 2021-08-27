class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans = 0, n = size(difficulty), i = 0, best = 0;
        vector<pair<int, int>> jobs;
        
        for (int i = 0; i < n; i++) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        
        sort(begin(jobs), end(jobs));
        sort(begin(worker), end(worker));
        
        for (const int w: worker) {
            while (i < n and w >= jobs[i].first) {
                best = max(best, jobs[i++].second);
            }
            
            ans += best;
        }
        
        return ans;
    }
};