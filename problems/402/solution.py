class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        i = 0
        
        while i < len(num) - 1 and k > 0:
            if i >= 0 and num[i] > num[i + 1]:
                num = num[:i] + num[i + 1:]
                i -= 2
                k -= 1
            
            i += 1
        
        while num and num[0] == '0':
            num = num[1:]
        
        return num[:len(num) - k] if len(num) - k >= 1 else '0'