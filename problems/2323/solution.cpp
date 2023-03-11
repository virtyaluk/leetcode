class Solution {
public:
    int minimumTime(vector<int>& jobs, vector<int>& workers) {
        int ans = 0;
        
        sort(begin(jobs), end(jobs));
        sort(begin(workers), end(workers));
        
        for (int i = 0; i < size(jobs); i++) {
            ans = max(ans, (int) ceil((float) jobs[i] / (float) workers[i]));
        }
        
        return ans;
    }
};