class Solution:
    def checkValidString(self, s: str) -> bool:
        leftBalance = rightBalance = 0
        
        for i in range(len(s)):
            leftBalance += 1 if s[i] in '(*' else -1
            rightBalance += 1 if s[~i] in ')*' else -1

            if leftBalance < 0 or rightBalance < 0:
                return False
        
        return True