class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = INT_MIN;
        
        for (vector<int> acc: accounts) {
            ans = max(ans, accumulate(acc.begin(), acc.end(), 0));
        }
        
        return ans;
    }
};