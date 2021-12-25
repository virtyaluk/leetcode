class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, iMax = 0;
        
        for (int i = 0; i < size(values); i++) {
            ans = max(ans, iMax + values[i] - i);
            iMax = max(iMax, values[i] + i);
        }
        
        return ans;
    }
};