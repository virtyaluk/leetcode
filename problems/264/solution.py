class Solution:
    def nthUglyNumber(self, n: int) -> int:
        ugly, nfo2, nfo3, nfo5, i2, i3, i5 = [0] * n, 2, 3, 5, 0, 0, 0
        ugly[0] = 1
        
        for i in range(1, n):
            ugly[i] = min(nfo2, nfo3, nfo5)
            
            if ugly[i] == nfo2:
                i2 += 1
                nfo2 = ugly[i2] * 2
            
            if ugly[i] == nfo3:
                i3 += 1
                nfo3 = ugly[i3] * 3
            
            if ugly[i] == nfo5:
                i5 += 1
                nfo5 = ugly[i5] * 5
        
        return ugly[n - 1]