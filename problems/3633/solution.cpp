class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX,
            minEnd = INT_MAX;
        
        for (int i = 0; i < size(landStartTime); i++) {
            minEnd = min(minEnd, landStartTime[i] + landDuration[i]);
        }

        for (int i = 0; i < size(waterStartTime); i++) {
            ans = min(ans, waterDuration[i] + max(minEnd, waterStartTime[i]));
        }

        minEnd = INT_MAX;

        for (int i = 0; i < size(waterStartTime); i++) {
            minEnd = min(minEnd, waterStartTime[i] + waterDuration[i]);
        }

        for (int i = 0; i < size(landStartTime); i++) {
            ans = min(ans, landDuration[i] + max(minEnd, landStartTime[i]));
        }

        return ans;
    }
};