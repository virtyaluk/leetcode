class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        ans, start, parentheses = "", 0, 0
        
        for i in range(len(s)):
            if s[i] == '(':
                parentheses += 1
            elif s[i] == ')':
                parentheses -= 1
                
                if parentheses == 0:
                    ans += s[start + 1:i]
                    start = i + 1
        
        return ans