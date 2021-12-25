class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        
        vector<int> rem(60, 0);
        
        for (int t: time) {
            if (t % 60 == 0) {
                ans += rem[0];
            } else {
                ans += rem[60 - t % 60];
            }
            
            rem[t % 60]++;
        }
        
        return ans;
    }
};