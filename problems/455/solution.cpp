class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0, i = 0, j = 0, m = size(g), n = size(s);
        
        sort(begin(g), end(g));
        sort(begin(s), end(s));
        
        while (i < m and j < n) {
            if (g[i] <= s[j]) {
                i++;
                ans++;
            }
            
            j++;
        }
        
        return ans;
    }
};