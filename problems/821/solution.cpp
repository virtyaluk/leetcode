class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size(), dist = pow(10, 5);
        vector<int> ans(n, INT_MAX);
        
        for (int i = 0; i < n; i++) {
            dist = s[i] == c ? 0 : dist + 1;
            ans[i] = min(ans[i], dist);
        }
        
        dist = pow(10, 5);

        for (int i = n - 1; i >= 0; i--) {
            dist = s[i] == c ? 0 : dist + 1;
            ans[i] = min(ans[i], dist);
        }
        
        return ans;
    }
};