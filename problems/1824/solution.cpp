class Solution {
public:
    int minSideJumps(vector<int>& ar) {
        int n = size(ar);
        vector<int> dp = {1, 0, 1};
        
        for (int i = 1; i < n - 1; i++) {
            vector<int> newDp(3);
            
            for (int r = 0; r < 3; r++) {
                if (ar[i] == r + 1 or ar[i + 1] == r + 1) {
                    newDp[r] = 1e6;
                } else {
                    newDp[r] = min(
                        dp[r],
                        1 + min(
                            dp[(r + 1) % 3],
                            dp[(r + 2) % 3]
                        )
                    );
                }
            }
            
            dp = newDp;
        }
        
        return *min_element(begin(dp), end(dp));
    }
};