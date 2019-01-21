class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if not s:
            return 0
        
        l = 0
        s = s.strip()
        i = len(s)
        
        while i > 0:
            i -= 1
            
            if s[i] != ' ':
                l += 1
            else:
                break
        
        return l