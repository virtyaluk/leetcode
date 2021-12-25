class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        r = [0] * n
        c = [0] * m
        
        for k in indices:
            r[k[0]] += 1
            c[k[1]] += 1
        
        count = 0
        
        for i in r:
            for j in c:
                if (i + j) % 2 == 1:
                    count += 1
        
        return count