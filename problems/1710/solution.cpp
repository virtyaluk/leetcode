class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans = 0;
        
        sort(begin(boxTypes), end(boxTypes), [](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[1] > rhs[1];
        });
        
        for (int i = 0; i < size(boxTypes) and truckSize > 0; i++) {
            ans += min(truckSize, boxTypes[i][0]) * boxTypes[i][1];
            truckSize -= boxTypes[i][0];
        }
        
        return ans;
    }
};