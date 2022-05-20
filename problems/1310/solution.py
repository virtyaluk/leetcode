class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        val, dp, ans = 0, [0] * len(arr), []
        
        for i in range(len(arr)):
            val ^= arr[i]
            dp[i] = val
        
        for li, ri in queries:
            if not li:
                ans.append(dp[ri])
            else:
                ans.append(dp[ri] ^ dp[li - 1])
        
        return ans