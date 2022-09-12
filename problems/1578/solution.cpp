class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0, n = size(colors);
        
        for (int i = 1, minTime = neededTime.front(), allTime = neededTime.front(); i < n; i++) {
            if (colors[i] == colors[i - 1]) {
                minTime = max(minTime, neededTime[i]);
                allTime += neededTime[i];
                
                if (i == n - 1) {
                    ans += allTime - minTime;
                }
            } else {
                ans += allTime - minTime;
                allTime = neededTime[i];
                minTime = neededTime[i];
            }
        }
        
        return ans;
    }
};