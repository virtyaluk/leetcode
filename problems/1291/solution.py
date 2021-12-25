class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ans, q = [], deque(list(range(1, 10)))
        
        while q:
            num = q.popleft()
            
            if num >= low:
                ans.append(num)
            
            d = num % 10 + 1
            
            if d <= 9 and num * 10 + d <= high:
                q.append(num * 10 + d)
        
        return ans