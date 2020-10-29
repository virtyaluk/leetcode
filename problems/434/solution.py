class Solution:
    def countSegments(self, s: str) -> int:
        s = s.strip()
        
        if not s:
            return 0
        
        count = 1
        
        for i in range(len(s)):
            if i - 1 >= 0 and s[i] == ' ' and s[i - 1] == ' ':
                continue
            
            if s[i] == ' ':
                count += 1
        
        return count
            