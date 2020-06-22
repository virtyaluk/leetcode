class Solution:
    def isHappy(self, n: int) -> bool:
        visited = set()
        
        while n != 1 and n not in visited:
            visited.add(n)
            n = sum(map(lambda x: int(x) ** 2, str(n)))
        
        return n not in visited