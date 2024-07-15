class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        if not k:
            return [0] * len(code)
        
        c, ans, n = code + code + code, [], len(code)
        
        for i in range(len(code)):
            if k < 0:
                ans.append(sum(c[n + i - abs(k):n + i]))
            else:
                ans.append(sum(c[n + i + 1: n + i + k + 1]))
        
        return ans