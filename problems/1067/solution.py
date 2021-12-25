class Solution:
    def digitsCount(self, d: int, low: int, high: int) -> int:
        return self.helper(high, d) - self.helper(low - 1, d)
    
    def helper(self, n: int, d: int) -> int:
        ans, pivot = 0, 1
        
        while n >= pivot:
            ans += n // (10 * pivot) * pivot + min(pivot, max(0, n % (pivot * 10) - d * pivot + 1))
            ans -= pivot if d == 0 else 0
            pivot *= 10
        
        return ans + 1