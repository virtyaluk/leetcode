import math

class Solution:
    def numTrees(self, n: int) -> int:
        return int(1 / (n + 1) * math.comb(2*n, n))