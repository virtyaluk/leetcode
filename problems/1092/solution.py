class Solution:
    def lcs(self, a, b) -> str:
        m, n = len(a), len(b)
        
        dp = [['' for _ in range(n + 1)] for _ in range(m + 1)]
        
        for i in range(m):
            for j in range(n):
                if a[i] == b[j]:
                    dp[i + 1][j + 1] = dp[i][j] + a[i]
                else:
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1], key=len)
        
        return dp[-1][-1]
    
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        ans, i, j = '', 0, 0
        
        for ch in self.lcs(str1, str2):
            while str1[i] != ch:
                ans += str1[i]
                i += 1
            
            while str2[j] != ch:
                ans += str2[j]
                j += 1
            
            ans += ch
            i += 1
            j += 1
        
        return ans + str1[i:] + str2[j:]