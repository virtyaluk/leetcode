class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = size(dist),
            ans = 0;
        vector<double> time;
        
        for (int i = 0; i < n; i++) {
            time.push_back((double) dist[i] / speed[i]);
        }
        
        sort(begin(time), end(time));
        
        for (int i = 0, startTime = 0; i < n and startTime < time[i]; i++, startTime++) {
            ans++;
        }
        
        return min(ans, n);
    }
};