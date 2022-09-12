class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double waitTime = 0.0;
        int lastTimei = INT_MIN;
        
        for (vector<int>& customer: customers) {
            int arrivali = customer[0], timei = customer[1];
            
            waitTime += 1.0 * (max(lastTimei, arrivali) + timei - arrivali);
            lastTimei = max(lastTimei, arrivali) + timei;
        }
        
        return waitTime / (double) customers.size();
    }
};