class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        a, b = set(), set()
        
        for ca, cb in paths:
            a.add(ca)
            b.add(cb)
        
        return (b - a).pop()