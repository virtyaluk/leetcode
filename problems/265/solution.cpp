class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) {
            return 0;
        }
        
        int n = costs.size(), k = costs[0].size();
        
        for (int i = 1; i < n; i++) {
            int firstMin = INT_MAX, secondMin = INT_MAX, firstMinIdx = -1;
            
            for (int j = 0; j < k; j++) {
                if (firstMin > costs[i - 1][j]) {
                    firstMin = costs[i - 1][j];
                    firstMinIdx = j;
                }
            }
            
            for (int j = 0; j < k; j++) {
                if (j != firstMinIdx) {
                    secondMin = min(secondMin, costs[i - 1][j]);
                }
            }
            
            for (int j = 0; j < k; j++) {
                if (j == firstMinIdx) {
                    costs[i][j] += secondMin;
                } else {
                    costs[i][j] += firstMin;
                }
            }
        }
        
        return *min_element(begin(costs[n - 1]), end(costs[n - 1]));
    }
    
    /*
        [
            [1, 5, 3],
            [2, 9, 4]
        ]
        
        0 1 2 n
        1 1 4 5
        2 5 2 7
        3 3 2 5
    */
    
    int minCostII1(vector<vector<int>>& costs) {
        if (costs.empty()) {
            return 0;
        }
        
        int ans = INT_MAX;
        
        for (int i = 0; i < costs[0].size(); i++) {
            dfs(costs, ans, 0, i, 0);
        }
        
        return ans;
    }
    
    void dfs(const vector<vector<int>>& costs, int& ans, int houseIdx, const int costIdx, int curCost) {
        curCost += costs[houseIdx][costIdx];
        houseIdx++;
        
        if (houseIdx >= costs.size()) {
            ans = min(ans, curCost);
            return;
        }
        
        if (curCost > ans) {
            return;
        }
        
        for (int i = 0; i < costs[0].size(); i++) {
            if (i != costIdx) {
                dfs(costs, ans, houseIdx, i, curCost);
            }
        }
    }
};