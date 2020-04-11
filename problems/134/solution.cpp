class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), totalTank = 0, curTank = 0, startStation = 0;
        
        for (int i = 0; i < n; i++) {
            totalTank += gas[i] - cost[i];
            curTank += gas[i] - cost[i];
            
            if (curTank < 0) {
                curTank = 0;
                startStation = i + 1;
            }
        }
        
        return totalTank >= 0 ? startStation : -1;
    }
};