import math

class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        x =  round(math.exp(math.log(num) / 2))
        
        return x * x == num