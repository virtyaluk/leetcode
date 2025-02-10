class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = size(rolls),
            nSum = mean * (n + m) - accumulate(begin(rolls), end(rolls), 0);
        
        if (nSum > 6 * n or nSum < n) {
            return {};
        }
        
        vector<int> ans(n, nSum / n);
        
        for (int i = 0; i < nSum % n; i++) {
            ans[i]++;
        }
        
        return ans;
    }
};