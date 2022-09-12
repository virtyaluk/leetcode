class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        ans, m, q = sys.maxsize, sys.maxsize, []
        
        for num in nums:
            if num % 2:
                heappush(q, -num * 2)
                m = min(m, num * 2)
            else:
                heappush(q, -num)
                m = min(m, num)
        
        while q:
            num = -heappop(q)
            ans = min(ans, num - m)
            
            if num % 2:
                break
            else:
                heappush(q, -num // 2)
                m = min(m, num // 2)
        
        return ans