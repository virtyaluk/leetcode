class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    ans += (pow(i, 2) + pow(j, 2) == pow(k, 2));
                }
            }
        }
    
        return ans;
    }
};