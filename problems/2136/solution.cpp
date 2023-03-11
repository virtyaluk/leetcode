class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<vector<int>> times;
        int ans = 0;
        
        for (int i = 0; i < size(plantTime); i++) {
            times.push_back({growTime[i], plantTime[i]});
        }
        
        sort(begin(times), end(times), greater<>());
        
        for (int i = 0, prevPlantTime = 0; i < size(times); i++) {
            int gTime = times[i][0],
                pTime = times[i][1];
            
            prevPlantTime += pTime;
            int bloomTime = prevPlantTime + gTime + 1;
            
            ans = max(ans, bloomTime);
        }
        
        return ans - 1;
    }
};