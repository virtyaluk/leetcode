class Solution {
public:
    // 3 1 2
    vector<int> decode(vector<int>& e) {
        int n = e.size() + 1, x = 0;
        vector<int> ans(n);
        
        for (int i = 1; i <= n; i++) {
            x ^= i;
        }
        
        ans[0] = x;
        
        for (int i = 1; i < n - 1; i += 2) {
            ans[0] ^= e[i];
        }
        
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] ^ e[i - 1];
        }
        
        return ans;
    }
};