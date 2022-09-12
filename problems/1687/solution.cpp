class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = size(boxes),
            dp[n];
        
        memset(dp, -1, sizeof(dp));
        
        return dfs(dp, boxes, maxBoxes, maxWeight, n - 1);
    }
    
    int dfs(
        int dp[],
        vector<vector<int>>& boxes,
        int mb,
        int mw,
        int i
    ) {
        if (i >= size(boxes)) {
            return 0;
        }
        
        if (dp[i] == -1) {
            int curBoxes = 0,
                curWeight = 0,
                trips = 1,
                prevTrips = -1,
                lastSeenPort = -1,
                lastSeenPortIdx = -1,
                transitions = 0,
                j = i;
            
            dp[i] = INT_MAX;
            
            for (; j >= 0; j--) {
                curBoxes++;
                curWeight += boxes[j][1];
                
                if (curBoxes > mb or curWeight > mw) {
                    break;
                }
                
                if (boxes[j][0] != lastSeenPort) {
                    transitions++;
                    lastSeenPort = boxes[j][0];
                    prevTrips = trips;
                    trips++;
                    lastSeenPortIdx = j;
                }
            }
            
            dp[i] = min(dp[i], trips + dfs(dp, boxes, mb, mw, j));
            
            if (transitions > 1) {
                dp[i] = min(dp[i], prevTrips + dfs(dp, boxes, mb, mw, lastSeenPortIdx));
            }
        }
        
        return dp[i];
    }
};