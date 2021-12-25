class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        ml = sum(-a if d else a for d, a in shift) % len(s)
        
        return s[ml:] + s[:ml]