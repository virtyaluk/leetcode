class Solution {
public:
    int maxHeight(vector<vector<int>>& A) {
        int ans = 0;
        vector<int> dp(A.size() + 1);
        
        for (vector<int>& cub: A) {
            sort(cub.begin(), cub.end());
        }
        
        A.push_back({0, 0, 0});
        
        sort(A.begin(), A.end());
        
        for (int i = 1; i < A.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (A[j][0] <= A[i][0] && A[j][1] <= A[i][1] && A[j][2] <= A[i][2]) {
                    dp[i] = max(dp[i], dp[j] + A[i][2]);
                    ans = max(ans, dp[i]);
                }
            }
        }
        
        return ans;
    }
};