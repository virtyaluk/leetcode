class Solution:
    def countDigitOne(self, n: int) -> int:
        ans, pivot = 0, 1
        
        while n >= pivot:
            ans += n // (10 * pivot) * pivot + min(pivot, max(0, n % (pivot * 10) - pivot + 1))
            pivot *= 10
        
        return ans