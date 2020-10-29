class Solution:
    def longestLine(self, mat: List[List[int]]) -> int:
        m, n, ans = len(mat), len(mat[0]), 0
        dp = [[0] * 4 for _ in range(n)]
        
        for i in range(m):
            newDp = [[0] * 4 for _ in range(n)]
            
            for j in range(n):
                if mat[i][j] == 1:
                    newDp[j][0] = 1 + newDp[j - 1][0] if j > 0 else 1
                    newDp[j][1] = 1 + dp[j - 1][1] if j > 0 else 1
                    newDp[j][2] = 1 + dp[j][2]
                    newDp[j][3] = 1 + dp[j + 1][3] if j + 1 < n else 1

                    ans = max(ans, max(newDp[j]))
            
            dp = newDp
        
        return ans