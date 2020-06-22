class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if x + y < z:
            return False
        
        if not z:
            return True
        
        if not x:
            return y == z
        
        if not y:
            return x == z
        
        return z % math.gcd(x, y) == 0