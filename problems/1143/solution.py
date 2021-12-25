class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = [[0 for i in range(len(text1) + 1)] for j in range(len(text2) + 1)]
        
        for i in range(1, len(dp)):
            for j in range(1, len(dp[0])):
                dp[i][j] = max(dp[i - 1][j] ,dp[i][j - 1])
                
                if text2[i - 1] == text1[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1 
                    
        return dp[-1][-1]