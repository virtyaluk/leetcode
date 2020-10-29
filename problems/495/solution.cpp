class Solution {
public:
    int findPoisonedDuration1(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) {
            return 0;
        }
        
        int ans = 0, end = timeSeries[0] + duration;
        ans += end - timeSeries[0];
        
        for (int i = 1; i < timeSeries.size(); i++) {
            int newEnd = timeSeries[i] + duration;
            
            ans += max(newEnd, end) - max(end, timeSeries[i]);
            end = newEnd;
        }
        
        return ans;
    }
    
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) {
            return 0;
        }
        
        int ans = 0;
        
        for (int i = 0; i < timeSeries.size() - 1; i++) {
            ans += min(timeSeries[i + 1] - timeSeries[i], duration);
        }
        
        return ans + duration;
    }
};