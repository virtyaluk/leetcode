class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        d = defaultdict(int)
        
        for ch in magazine:
            d[ch] += 1
        
        for ch in ransomNote:
            if d[ch]:
                d[ch] -= 1
            else:
                return False
        
        return True